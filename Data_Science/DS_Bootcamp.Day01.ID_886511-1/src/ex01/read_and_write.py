def is_delimiter_comma(line: str, pos: int) -> bool:
    """Определяет, является ли запятая разделителем столбцов (а не частью данных).
    
    Args:
        line (str): Строка CSV для анализа.
        pos (int): Позиция запятой в строке.
        
    Returns:
        bool: True, если запятая является разделителем столбцов (вне кавычек).
        
    """
    in_quotes = False
    for i, char in enumerate(line[:pos]):
        if char == '"':
            in_quotes = not in_quotes
    return not in_quotes

def convert_line_to_tsv(line: str) -> str:
    """Конвертирует строку CSV в TSV, заменяя только разделяющие запятые на табы.
    
    Обрабатывает строку CSV, сохраняя запятые внутри кавычек (данных) неизменными.
    Например: '"ООО ""Рога"", 2024",100,000' -> '"ООО ""Рога"", 2024"\t100\t000'.

    Args:
        line (str): Строка в формате CSV (с кавычками и запятыми-разделителями).

    Returns:
        str: Строка в формате TSV, где разделители заменены на табы (\t).

    Raises:
        ValueError: Если строка содержит несбалансированные кавычки.

    """
    if line.count('"') % 2 != 0:
        raise ValueError("Несбалансированные кавычки в строке")
    result = []
    i = 0
    while i < len(line):
        if line[i] == ',' and is_delimiter_comma(line, i):
            result.append('\t')
            i += 1
        else:
            result.append(line[i])
            i += 1
    return ''.join(result)

def process_file(input_path: str, output_path: str) -> None:
    """Читает CSV-файл, конвертирует его в TSV и сохраняет результат.

    Обрабатывает входной CSV-файл, заменяя разделители-запятые на табы (\t),
    при этом корректно сохраняя запятые внутри кавычек (данных). Результат
    записывается в TSV-файл.

    Args:
        input_path (str): Путь к исходному CSV-файлу.
        output_path (str): Путь для сохранения TSV-файла.

    Raises:
        FileNotFoundError: Если входной файл не существует.
        IOError: При ошибках чтения/записи файлов.
        ValueError: Если CSV содержит несбалансированные кавычки.

    """
    try:
        with open(input_path, 'r', encoding='utf-8') as csv_file:
            with open(output_path, 'w', encoding='utf-8') as tsv_file:
                for line in csv_file:
                    tsv_file.write(convert_line_to_tsv(line))
    except FileNotFoundError:
        raise FileNotFoundError(f"Файл {input_path} не найден")
    except IOError as e:
        raise IOError(f"Ошибка ввода/вывода: {str(e)}")
if __name__ == '__main__':
    process_file('../ds.csv', 'ds.tsv')