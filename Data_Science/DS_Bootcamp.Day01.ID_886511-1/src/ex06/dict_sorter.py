def sort_countries():
    """Сортирует страны по номерам в убывающем порядке, а при совпадении номеров - по алфавиту.
    Выводит названия стран по одному в строке без номеров."""
    
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

    country_to_number = {country: int(number) for country, number in list_of_tuples}

    sorted_countries = sorted(country_to_number.items(),
                            key=lambda x: (-x[1], x[0]))

    for country, _ in sorted_countries:
        print(country)

if __name__ == '__main__':
    sort_countries()