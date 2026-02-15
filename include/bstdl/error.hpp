#include <signal.h>

#include <execinfo.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>

void print_stacktrace()
{
    const int max_frames = 64;
    void* frames[max_frames];

    int frame_count = backtrace(frames, max_frames);
    char** symbols = backtrace_symbols(frames, frame_count);

    if (!symbols) {
        perror("backtrace_symbols");
        return;
    }

    for (int i = 0; i < frame_count; ++i) {
        fprintf(stderr, "%s\n", symbols[i]);
    }

    fflush(stderr);

    free(symbols);
}

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define BUG_ON(condition) do { \
    if(condition) { \
        fprintf(stderr, "Assertion failed: `!(" #condition ")`.\n"); \
        fprintf(stderr, "In %s, at %s:%d\n", __FILE__, __PRETTY_FUNCTION__, __LINE__); \
        fflush(stderr); \
        fprintf(stderr, "\nStack frame:\n"); \
        print_stacktrace(); \
        raise(SIGABRT); \
    } } while (0);

#undef STRINGIFY
#undef TOSTRING
