# Container

Container C++11 Implementation
------------------------------------

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
OBS: This project was tested under 

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
