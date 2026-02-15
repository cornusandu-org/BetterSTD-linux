# BetterSTD-linux (Better
#### An extension of the C++ Standard Library, recommended for Linux

---

> [!IMPORTANT]  
> BetterSTD-linux is **not** a replacement for the default standard library, nor is it meant to be. It is simply an extension meant to be used alongside the standard library.

> [!TIP]
> BetterSTD-linux contains certain functions that only work on Linux/UNIX/Posix. If you want a cross-platform-only version, check out [BetterSTDL (Original)](https://github.com/cornusandu-org/BetterSTD).
<br>

<details>
<summary><h2>bstdl/libstdc</h2></summary>
BetterSTD also provides some re-implementations of libstdc that aim to be cross-platform. These functions are:
* `POINT alloc_mem(POINT base, size_t size)`: mmap / VirtualAlloc
* `Page alloc_page(POINT base, PageSize size = PageSize::NORMAL)`: mmap / VirtualAlloc (for a single, entire page)
* `BOOL dealloc_mem(POINT base, size_t len)`: munmap / VirtualFree
* `BOOL dealloc_page(const Page& page)`: munmap / VirtualFree (for a single, entire page)
* `BOOL protect_mem(POINT base, size_t size, _MemProtect protect, _MemBehaviour behaviour)`: mprotect / VirtualProtect
* `BOOL protect_page(Page page, _MemProtect protect, _MemBehaviour behaviour)`: mprotect / VirtualProtect (for a single, entire page)

The `Pointer` class is a thin wrapper around `void*`.

> [!CAUTION]
> We advise against use of `Pointer` in normal code, unless the pointer of origin is, in itself, a `void*`.

The `Page` class is a struct, containing relevant information about the page:
```cpp
struct Page {
    Pointer location;
    PageSize size;
    _MemProtect prot = MemProtect::READ | MemProtect::WRITE;
    _MemBehaviour behaviour = 0;
};
```

The page sizes are `PageSize::NORMAL` (4KiB), `PageSize::LARGE` (2MiB), `PageSize::HUGE` (1GiB).

The MemProtect values (combine with `|`) are: `MemProtect::NONE`, `MemProtect::READ`, `MemProtect::WRITE`, `MemProtect::EXECUTE`, `MemProtect::COPY`.

The MemBehaviour values (combine with `|`) are: `MemBehaviour::NOCACHE`, `MemBehaviour::WRITECOMBINE`.

> [!CAUTION]  
> `MemBehaviour::NOCACHE` and `MemBehaviour::WRITECOMBINE` can only be fully implemented on Windows, but are "simulated" on Linux via `madvise()`.

You will also have top-level names **replacing** those of `windows.h` with cross-platform alternatives:
* `POINT` -> `bstdl::POINT` -> `bstdl::Pointer`
* `BOOL` -> `bstdl::BOOL` -> `bstdl::uint8_t` -> `unsigned char`
* `PDWORD` -> `bstdl::luint*` -> `long unsigned int*`

Additionally, some aliases for ease-of-use:
* `u8` -> `bstdl::uint8_t` -> `unsigned char`
* `u16` -> `std::uint16_t`
* `u32` -> `bstdl::uint32_t` -> `std::uint32_t`
* `u64` -> `std::uint64_t`
* `int8` -> `signed char`
* `int16` -> `std::int16_t`
* `int32` -> `std::int32_t`
* `int64` -> `std::int64_t`
* `s8` -> `int8` -> `signed char`
* `s16` -> `int16` -> `std::int16_t`
* `s32` -> `int32` -> `std::int32_t`
* `s64` -> `int64` -> `std::int64_t`
* `i8` -> `int8` -> `signed char`
* `i16` -> `int16` -> `std::int16_t`
* `i32` -> `int32` -> `std::int32_t`
* `i64` -> `int64` -> `std::int64_t`
* `byte` -> `u8` -> `bstdl::uint8_t` -> `unsigned char`
* `sbyte` -> `int8` -> `signed char`
* `schar` -> `i8` -> `int8` -> `signed char`
* `cstring` -> `bstdl::cstring` -> `char*`
* `cstr` -> `cstring` -> `bstdl::cstring` -> `char*`
* `luint` -> `bstdl::luint` -> `long unsigned int`
* `uptr` -> `uintptr_t`
* `qword_t` -> `u64` -> `std::uint64_t`
* `sqword_t` -> `i64` -> `int64` -> `std::int64_t`

> [!NOTE]
> These lists may be expanded in the future, and aliases may change.
</details>
<br>

<details>
<summary><h2>bstdl/rand</h2></summary>

BetterSTD's `rand` headers provide:
* ~~`bstdl::random::uniform`: Random value in the range of [0, 1]~~ (deprecated)
* ~~`bstdl::random::randint`: Random value in the range of [a, b]~~ (deprecated)
* `bstdl::random::Generator`
    * `double Generator::uniform()`: Random value in the range of [0, 1)
    * `double* Generator::generate_batch(size_t count)`: Returns an array of `count` random values in the range of [0, 1)
    * `size_t Generator::randint(size_t low, size_t high)`: Random value in the range of [low, high)
</details>
<br>

<details>
<summary><h2>bstdl/sort</h2></summary>
BetterSTD's `sort` header provides:
* `sort`: A multi-threaded implementation of quick sort, intended for really large arrays (>1024 items)
</details>
<br><br><br><br>
<p align="center">© Copyright 2025-2026 cornusandu, Licensed under the <b>MIT License</b></p>
