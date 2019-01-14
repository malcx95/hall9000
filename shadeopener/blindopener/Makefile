TARGET=armv7-unknown-linux-gnueabihf

IP=192.168.1.180

ring_pien:
	cargo build --target ${TARGET}
	scp "target/${TARGET}/debug/blindopener" "${IP}:~/bin/blindopener"
