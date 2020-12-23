all: bserver bclient
	

bserver:
	g++ -o bin/server -iquote include src/server/*.cpp src/sockio/*.cpp

bclient:
	g++ -o bin/client -iquote include src/client/*.cpp src/sockio/*.cpp

