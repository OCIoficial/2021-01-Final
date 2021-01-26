#!/usr/bin/python
import sys
import argparse
from collections import Counter
from typing import Generator, TextIO


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


def normalize_paragraph(paragraph: str) -> str:
    normalized = []
    should_append_space = False
    for c in paragraph:
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


def generate_paragraph(chapter: str) -> Generator[str, None, None]:
    for paragraph in chapter.split('\n\n')[1:]:
        yield paragraph


def generate_chapter(f: TextIO) -> Generator[str, None, None]:
    for chapter in f.read().split('\n\n\n\n\n\n'):
        yield chapter


def extract_paragraph(filename: str, num_chapter: int, num_paragraph: int) -> str:
    with open(filename, "r") as f:
        for num_c, chapter in enumerate(generate_chapter(f), start=1):
            if num_chapter > num_c:
                continue
            for num_p, paragraph in enumerate(generate_paragraph(chapter), start=1):
                if num_paragraph > num_p:
                    continue
                return normalize_paragraph(paragraph.strip())


def print_stats_for_file(filename: str) -> None:
    with open(filename, "r") as f:
        print("chapter,paragraph,totalalpha,1st frequent,1st percent,2nd frequent,2nd percent,3rd frequent,3rd percent,one_letter_words,prefix")
        for num_c, chapter in enumerate(generate_chapter(f), start=1):
            for num_p, paragraph in enumerate(generate_paragraph(chapter), start=1):
                print_stats_for_paragraph(normalize_paragraph(paragraph.strip()), num_c, num_p)


def print_stats_for_paragraph(paragraph: str, num_c: int, num_p: int) -> str:
    total = 0
    counter = Counter()
    letters = [c for c in paragraph if c.isalpha()]
    one_letter_words = list({word for word in paragraph.split() if len(word) == 1})
    counter.update(letters)
    total = len(letters)
    length = len(paragraph)
    if total >= 30:
        print(",".join([
            str(num_c),
            str(num_p),
            str(length),
            str(total),
            *map(lambda pair: f"{pair[0]},{pair[1]/total*100:.4f}%", counter.most_common(3)),
            "-".join(one_letter_words), paragraph[:20]
        ]))
    return str


if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog="paragraphs.py")
    subparsers = parser.add_subparsers(dest='command', required=True)
    extract_parser = subparsers.add_parser('extract')
    extract_parser.add_argument('filename')
    extract_parser.add_argument('-c', '--chapter', type=int, required=True)
    extract_parser.add_argument('-p', '--paragraph', type=int, required=True)
    extract_parser.add_argument('-l', '--length', action=argparse.BooleanOptionalAction, default=True)
    stats_parser = subparsers.add_parser('stats')
    stats_parser.add_argument('filename')

    args = parser.parse_args()

    if args.command == "extract":
        paragraph = extract_paragraph(args.filename, args.chapter, args.paragraph)
        if (args.length):
            print(len(paragraph))
        print(paragraph)
    elif args.command == "stats":
        print_stats_for_file(args.filename)
