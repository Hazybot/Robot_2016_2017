CC=gcc
CFLAGS=-Wall -g -DDEBUG
EFLAGS=-pthread

srcExt=.c
headerExt=.h

launcher=test.out

scriptDir=$(shell pwd)
objectDir=bin
srcDir=src

directories=$(shell find $(srcDir) -type d | sed '1d')

srcFile=$(foreach dir, $(directories), $(wildcard $(dir)/*$(srcExt)))

headers=$(foreach dir, $(directories), $(wildcard $(scriptDir)/$(dir)/*$(headerExt)))

objects=$(foreach file, $(srcFile:$(srcExt)=.o), $(objectDir)/$(notdir $(file)))

all: $(launcher)

#all:
#	@echo $(scriptDir)/$(objectDir)

$(launcher): compilation
	$(CC) -o $(launcher) $(objects) $(EFLAGS)

compilation:
	@mkdir $(objectDir) -p
	@for dir in $(directories); do \
		if [ ! `ls $$dir | grep $(srcExt) | wc -l` -eq 0 ]; then \
			if [ ! -e $$dir/Makefile ]; then \
					cp Makefile_type $$dir/Makefile; \
			fi; \
			make --no-print-directory -C $$dir objectDir="$(scriptDir)/$(objectDir)" headers="$(headers)" CC=$(CC) CFLAGS="$(CFLAGS)" srcExt="$(srcExt)" headerExt="$(headerExt)";	\
		fi; \
	done

clean_all: clean
	rm $(launcher)

clean:
	rm -R $(objectDir)

clean_error:
	@for dir in $(directories); do \
		rm -f $$dir/*.o; \
	done

clean_Makefile:
	@for dir in $(directories); do	\
		rm -f $$dir/Makefile;	\
	done
