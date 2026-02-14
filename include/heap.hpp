#pragma once

#include <cstdlib>

namespace bstdl {
namespace heap {
void init();
void *alloc(size_t size);
void dealloc(void* base);
}
}
