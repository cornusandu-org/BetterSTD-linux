#pragma once

#include <cstdlib>

namespace bstdl {
namespace heap {
extern void init();
extern void *alloc(size_t size);
extern void dealloc(void* base);
}
}
