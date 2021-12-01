import sys


def get_day_from_file(filename):
    """retrieves an integer stored on the first line of a textfile"""
    try:
        f = open(filename)
    except FileNotFoundError:
        print("File not found, exiting...")
        exit()

    current_day = f.read()
    f.close()

    if len(current_day) == 0:
        print("No day set, exiting...")
        exit()

    return int(current_day)


def increment_day(filename, current_day):
    """writes an integer to a given file"""
    f = open(filename, "w")
    print("Incrementing day...")
    f.write(str(current_day + 1))
    f.close()


def create_file(filename):
    """creates a file with the given filename"""
    print("Creating file:", filename)
    try:
        open(filename, "x")
    except FileExistsError:
        print("File already exists.")


if __name__ == "__main__":
    # Get the current day either from file or from command line arg
    if len(sys.argv) == 1:
        current_day = get_day_from_file("current_day.txt")
    else:
        current_day = int(sys.argv[1])

    # Construct filenames
    python_name = f"day-{current_day}.py"
    input_name = f"input-{current_day}.txt"

    # Create files
    create_file(python_name)
    create_file(input_name)

    # Increment day if we got it from file
    if len(sys.argv) == 1:
        increment_day("current_day.txt", current_day)

    print("Done, exiting...")
