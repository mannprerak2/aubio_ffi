## C Source code for Aubio

Original Source
- Repo: https://github.com/aubio/aubio
- Commit: [8a05420e5dd8c7b8b2447f82dc919765876511b3](https://github.com/aubio/aubio/commit/8a05420e5dd8c7b8b2447f82dc919765876511b3)

### Notes

The source is mostly unmodified except-
1. Changing the `#include` statements at multiple places to use correct relative paths.
2. Added an `aubio_ffi.c` file which imports all the symbols exported and adds `#defines`.
