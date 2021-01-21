#!/usr/bin/python
import sys
import argparse
from typing import Counter, Iterable, Tuple


def unaccent(c: str) -> str:
    assert(c.isalpha() and len(c) == 1 and c.isupper())
    map = {'Á': 'A', 'É': 'E', 'Í': 'I', 'Ó': 'O', 'Ú': 'U',
           'Ä': 'A', 'Ë': 'E', 'Ï': 'I', 'Ü': 'U', 'Ù': 'U', 'À': 'A'}
    c = map.get(c, c)
    if not (ord('A') <= ord(c) <= ord('Z') or c == 'Ñ'):
        print(f'Unexpected alpha character >{c}<', file=sys.stderr)
        sys.exit()
    return c


def ispunctuation(c: str) -> str:
    return c in {'¡', '!', '.', ',', ';', ':', '¿', '?', '-', '«', '»', "'", '(', ')', '"'}


def normalize_line(line: str) -> str:
    normalized = []
    should_append_space = False
    for c in line:
        if c.isalpha():
            normalized.append(unaccent(c.upper()))
            should_append_space = True
        elif c.isspace():
            if should_append_space:
                should_append_space = False
                normalized.append(' ')
        elif ispunctuation(c) or c.isnumeric():
            should_append_space = True
        else:
            print(f'Unexpected character: >{c}<', file=sys.stderr)
            sys.exit()
    return ''.join(normalized)


def normalize_lines(lines: Iterable[str]) -> str:
    normalized = []
    for line in lines:
        line = line.strip()
        if len(line) == 0:
            continue
        normalized.append(normalize_line(line))
    return '\n'.join(normalized)


def normalize_file(filename: str) -> str:
    with open(filename, "r") as f:
        return normalize_lines(f)


def stats_for_file(filename: str) -> Tuple[Counter[str], int]:
    with open(filename, "r") as f:
        total = 0
        counter = Counter()
        for line in f:
            letters = [c for c in line if c.isalpha()]
            counter.update(letters)
            total += len(letters)
        return (counter, total)


def print_stats(stats: Tuple[Counter[str], int]):
    (counter, total) = stats
    print(f"Total: {total}")
    for (k, c) in counter.most_common():
        print(f"{k}\t{c/total*100:10.4f}%\t{c}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog="quijote")
    subparsers = parser.add_subparsers(dest='command')
    normalize_parser = subparsers.add_parser('normalize')
    normalize_parser.add_argument('filename')

    stats_parsers = subparsers.add_parser('stats')
    stats_parsers.add_argument('filename')

    args = parser.parse_args()
    if args.command == "stats":
        print_stats(stats_for_file(args.filename))
    elif args.command == "normalize":
        print(normalize_file(args.filename))
