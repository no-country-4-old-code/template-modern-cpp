import re
import utils.utils as utils


def _truncate_line(line, max_length):
    output = line.strip()    
    if len(output) > max_length:
        output = output[:(max_length - 3)] + '...'
    return output


def _find_comments_with_tags_in_file(path):
    max_comment_length = 25
    pattern = re.compile(r'^\s*(#|//)\s*(TODO|FIXME|WTF)', re.IGNORECASE)

    with open(path, 'r', encoding='utf-8') as file:
        for line_num, line in enumerate(file, start=1):
            if pattern.search(line):
                truncated_line = _truncate_line(line, max_comment_length)
                print(f"{truncated_line:<25} @ line {line_num:>3} in {path}")


def find_comments_with_tags(files):
    """
    Scans files for TODO, FIXME, or WTF comments and prints links to those lines.
    """
    for filename, path in files.items():
        try:
            _find_comments_with_tags_in_file(path)            

        except FileNotFoundError:
            print(f"Error: File not found - {path}")

        except Exception as e:
            print(f"Error reading {path}: {e}")


if __name__ == "__main__":
    directory = utils.get_input_arguments()
    files = utils.find_source_files(directory)
    find_comments_with_tags(files)
