def convert_to_dictionary():
    """Преобразует жестко заданный список кортежей (страна, число) в и cоздает "словарь", где:
       - Ключи: числа из кортежей (в виде строк)
       - Значения: списки стран, соответствующих каждому числу
    Выводит результат в формате:
       'число' : 'страна' с каждой парой на новой строке
    Особенности:
    - Одно число может соответствовать нескольким странам (пр, '132' для Франции и Германии)
    - Сохраняет исходные строковые значения без преобразования типов
    - Порядок вывода может отличаться от исходного списка
    
    """
    list_of_tuples = [
        ('Russia', '25'),
        ('France', '132'),
        ('Germany', '132'),
        ('Spain', '178'),
        ('Italy', '162'),
        ('Portugal', '17'),
        ('Finland', '3'),
        ('Hungary', '2'),
        ('The Netherlands', '28'),
        ('The USA', '610'),
        ('The United Kingdom', '95'),
        ('China', '83'),
        ('Iran', '76'),
        ('Turkey', '65'),
        ('Belgium', '34'),
        ('Canada', '28'),
        ('Switzerland', '26'),
        ('Brazil', '25'),
        ('Austria', '14'),
        ('Israel', '12')
    ]

    number_to_countries = {}
    for country, number in list_of_tuples:
        if number not in number_to_countries:
            number_to_countries[number] = []
        number_to_countries[number].append(country)
        print(f"'{number}' : '{country}'")

if __name__ == '__main__':
    convert_to_dictionary()
