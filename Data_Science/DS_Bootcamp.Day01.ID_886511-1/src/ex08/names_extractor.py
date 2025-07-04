import sys

def process_emails(input_file):
    """Читает входной файл с email-адресами, извлекает имена и фамилии, 
    сохраняет их в файл.tsv (значения, разделенные табуляцией)
    с колонками: Name, Surname, E-mail.

    Args:
        input_file (str): Путь к входному файлу.txt с кодировкой UTF-8.

    Returns:
        None: Функция не возвращает значение, но создает файл 'employees.tsv' 
        в рабочей директории.

    Raises:
        FileNotFoundError: Если указанный input_file не существует.
        ValueError: Если email имеет некорректный формат (отсутствует '@' или '.' в локальной части).
        IOError: При проблемах с записью в выходной файл.
    """
    with open(input_file, 'r') as f:
        emails = [line.strip() for line in f if line.strip()]
    
    employees = []
    for email in emails:
        if '@' not in email:
            continue
        name_part = email.split('@')[0]
        name, surname = name_part.split('.')
        employees.append([
            name.capitalize(),
            surname.capitalize(),
            email
        ])
    
    with open('employees.tsv', 'w') as f:
        f.write("Name\tSurname\tE-mail\n")
        for emp in employees:
            f.write("\t".join(emp) + "\n")

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Необходимо указать путь к файлу со списком email-ов: python names_extractor.py <emails.txt>")
        sys.exit(1)
    
    process_emails(sys.argv[1])