import sys

def find_employee(email):
    """Ищет сотрудника по точному совпадению email файле.tsv и возвращает его имя.
    
    Args:
        email (str): Email сотрудника для поиска (например, 'ivan.petrov@corp.com').
                    Должен полностью совпадать с записью в файле, включая регистр.

    Returns:
        str | None: Имя сотрудника (в том виде, как записано в файле) или None,
                   если сотрудник не найден или файл не существует.

    Raises:
        FileNotFoundError: Если 'файл.tsv' не существует (перехватывается
                         внутри функции, возвращает None).
        ValueError: Если строка в файле имеет некорректный формат (не хватает
                   значений или разделителей)."""
    try:
        with open('employees.tsv', 'r') as f:
            next(f)
            for line in f:
                name, surname, emp_email = line.strip().split('\t')
                if emp_email == email:
                    return name
    except FileNotFoundError:
        return None

def generate_greeting(name):
    """Генерирует стандартное приветственное письмо для нового сотрудника
       с обращением по имени
    Args:
        name (str): Имя сотрудника. Должно быть в правильном падеже, 
        регистр сохраняется как передан.

    Returns:
        str: Текст письма
    """
    return (f"Дорогой {name}, добро пожаловать в нашу команду. Мы уверены," 
    "что нам будет приятно работать с тобой. Это обязательное условие для"
    " профессионалов, которых нанимает наша компания.")

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Для генерации письма, нужно указать e-mail: python letter_starter.py <email>")
        sys.exit(1)
    
    email = sys.argv[1]
    name = find_employee(email)
    
    if name:
        print(generate_greeting(name))
    else:
        print(f"Сотрудник с таким  email {email} не найден")