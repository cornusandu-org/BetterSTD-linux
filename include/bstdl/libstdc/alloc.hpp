#pragma once

#include <cstdint>
#include <cstdlib>

#include "page.hpp"
#include "memprot.hpp"
#include "os.hpp"
#include "conv.hpp"

extern POINT alloc_mem(POINT base, size_t size);
extern Page alloc_page(POINT base, PageSize size = PageSize::NORMAL);

extern BOOL dealloc_mem(POINT base, size_t len);
extern BOOL dealloc_page(const Page& page);

extern BOOL protect_mem(POINT base, size_t size, _MemProtect protect, _MemBehaviour behaviour);
extern BOOL protect_page(Page page, _MemProtect protect, _MemBehaviour behaviour);
