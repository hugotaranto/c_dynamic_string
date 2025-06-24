# Dynamic C String Library

This is a very simple dynamic c string library intended to be used as a git submodule in other projects.

---

Add as a submodule to git projects by:

1. making a 'modules' directory

2. within that directory using:
~~~bash
git add submodule https://github.com/hugotaranto/c_dynamic_string.git"
~~~
3. Add to the CMakeLists.txt of the project:

```cmake
add_subdirectory(modules/c_dynamic_string)
target_link_libraries(proj PRIVATE dynamic_string)
```

You should then be able to build the project as normal and use:
~~~c
#include "dynamic_string.h"
~~~
---
## Usage
### Initialising and Freeing
~~~c
DynamicString *string = dstring_initialise();
~~~
or to specify initial size:
~~~c
DynamicString *string = dstring_initialise_size(size_t size);
~~~

These are then paired with:
~~~c
dstring_free(DynamicString *dstring);
~~~

### Functionality
To append a character onto the end of a string:
~~~c
dsttring_append(DynamicString *dstring, char ch);
~~~
To read lines in from a file stream:
~~~c
dstring_readline(DynamicString *dstring, FILE *stream);
~~~
e.g. for stdin:
~~~c
dstring_readline(dstring, stdin);
~~~
