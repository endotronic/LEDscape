#########
#
# Top level Makefile.
# Mostly just recurse into subdirectories.

SUBDIR-y += dts
SUBDIR-y += src/ledscape
SUBDIR-y += src/script
SUBDIR-y += src/ledgames
SUBDIR-y += src/ledgames/rsrc

all: 
	for dir in $(SUBDIR-y); do \
		$(MAKE) -C $$dir || exit 1; \
	done

clean:
	for dir in $(SUBDIR-y); do \
		$(MAKE) -C $$dir clean; \
	done


firmware:
	echo CAPE-BONE-OCTO > /sys/devices/bone_capemgr.8/slots

