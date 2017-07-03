# Container 
![Build Status](https://travis-ci.org/rdamacedo/container.svg?branch=master) [![Coverage Status](https://coveralls.io/repos/github/rdamacedo/container/badge.svg?branch=master)](https://coveralls.io/github/rdamacedo/container?branch=master)

Container C++11 Implementation
------------------------------------

It's basically an implementation of a templatized hashtable inside a Container. This Container class acts like a Manager controlling how itens will be pushed and retrieved. 

## Usage

### Example of input

```bash
CREATE mycontainer key=string value=int N=3
ADD mycontainer "mykey1" 42
ADD mycontainer "mykey2" 17
ADD mycontainer "mykey3" 19
ADD mycontainer "mykey4" 0 
GET mycontainer "mykey1" 
DESTRUCT mycontainer 
```

## Building

To use the functionality below however, you must use cmake to generate
the makefiles.
OBS: This project was tested under CentOS 6.5 and macOS 10.12.

```bash
mkdir build
cd build
cmake ..
make 
```

### Testing

From build directory:

```bash
make test
```

## License

Licensed under [the Apache 2.0 license](LICENSE). 
