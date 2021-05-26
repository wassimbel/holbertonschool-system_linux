#!/usr/bin/python3
""" script that finds a string in the heap of a running process,
    and replaces it """

import sys


def print_usage():
    """ print message to stdout and exit with status code 1 """
    print("read_write_heap.py pid search_string replace_string")
    exit(1)


def parse_args():
    """ returns pid(argv[1]), search_string(argv[1])
        and replace_string(argv[3]) """
    if len(sys.argv) != 4:
        print_usage()

    pid = int(sys.argv[1])
    search_string = (sys.argv[2])
    replace_string = (sys.argv[3])

    if pid < 1:
        print("pid of the process is less than 1 ")
        exit(1)

    if len(replace_string) > len(search_string):
        print("replace string should be less or equal to search_string")
        exit(1)

    return(pid, search_string, replace_string)


def parse_maps(pid):
    """ method that takes 1 patameter (argv[1])
        1: pid of the process """

    try:
        with open("/proc/{}/maps".format(pid), "r") as maps:
            for line in maps:
                if line.endswith("[heap]\n"):
                    start, end = \
                        [int(x, 16) for x in line.split(" ")[0].split("-")]
    except Exception as e:
        print(e)
        exit(1)

    return start, end


def mem_hack(pid, search_string, replace_string, start, end):
    """ replace search string with replace_string
        takes 5 parameters """
    try:
        with open("/proc/{}/mem".format(pid), "r+b") as mem:
            mem.seek(start)
            data = mem.read(end - start)
            string = data.index(bytes(search_string, "ASCII"))
            mem.seek(start + string)
            written = mem.write(bytes(replace_string + '\0', "ASCII"))
    except Exception as e:
        print(e)
        exit(1)


def main():
    pid, search_string, replace_string = parse_args()
    start, end = parse_maps(pid)
    mem_hack(pid, search_string, replace_string, start, end)


if __name__ == "__main__":
    main()
