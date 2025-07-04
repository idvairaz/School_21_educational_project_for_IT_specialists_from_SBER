import sys

def check_language(text):
    """Проверяет, содержит ли входящий аргумент кириллицу"""
    for char in text:
        if '\u0400' <= char <= '\u04FF':
            raise ValueError("Скрипт пока не поддерживает ваш язык")

def caesar_cipher(text, shift, mode='encode'):
    """Применяет шифр Цезаря к тексту"""
    result = []
    shift = shift if mode == 'encode' else -shift
    
    for char in text:
        if 'a' <= char <= 'z':
            new_char = chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
        elif 'A' <= char <= 'Z':
            new_char = chr((ord(char) - ord('A') + shift) % 26 + ord('A'))
        else:
            new_char = char 
        result.append(new_char)
    
    return ''.join(result)

if __name__ == '__main__':
    try:
        if len(sys.argv) != 4:
            raise ValueError("Не валидное колличество аргументов во входящей строке, требуется:" \
            "python3 caesar.py [encode|decode] 'текст' сдвиг(целое число)")
        
        mode = sys.argv[1]
        text = sys.argv[2]
        
        try:
            shift = int(sys.argv[3])
        except ValueError:
            raise ValueError("Сдвиг должен быть целым числом")
        
        if mode not in ('encode', 'decode'):
            raise ValueError("Первый аргумент должен быть 'encode' или 'decode'")
        
        check_language(text)
        
        result = caesar_cipher(text, shift, mode)
        print(result)
    
    except ValueError as e:
        print(f"Ошибка: {e}")
        sys.exit(1)