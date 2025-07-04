import sys

def process_stock_queries():
    """Обрабатывает переданный через командную строку 
       запрос и выводит соответствующую информацию.
    Поддерживает два типа запросов:
    - Поиск компании по тикеру (выводит название компании)
    - Поиск цены акций по названию компании (выводит текущую цену)

    Обработка ввода:
    - Принимает один аргумент командной строки - строка в кавычках с запросами через запятую
    - Игнорирует пустые запросы (",," или ", ,")

    Форматы вывода:
    - Для тикеров: "{ТИКЕР} is a ticker symbol for {НАЗВАНИЕ_КОМПАНИИ}"
    - Для названий компаний: "{КОМПАНИЯ} stock price is {ЦЕНА}"
    - Для неизвестных запросов: "{ЗАПРОС} is an unknown company or an unknown ticker symbol"

    Примеры вызова:
    python script.py "AAPL, Microsoft, INVALID"
    
    Пример вывода:
    AAPL is a ticker symbol for Apple
    Microsoft stock price is 173.79
    INVALID is an unknown company or an unknown ticker symbol

    """
    COMPANIES = {
        'Apple': 'AAPL',
        'Microsoft': 'MSFT',
        'Netflix': 'NFLX',
        'Tesla': 'TSLA',
        'Nokia': 'NOK'
    }

    STOCKS = {
        'AAPL': 287.73,
        'MSFT': 173.79,
        'NFLX': 416.90,
        'TSLA': 724.88,
        'NOK': 3.37
    }

    if len(sys.argv) != 2:
        return

    queries = sys.argv[1].strip()
    if not queries or ',,' in queries or ', ,' in queries:
        return

    items = [item.strip() for item in queries.split(',')]
    if not items:
        return
  
    for item in items:
        item_capitalize = item.capitalize()
        item_upper = item.upper()

        if item_upper in STOCKS:
            company = next((k for k, v in COMPANIES.items() if v == item_upper), None)
            print(f"{item_upper} is a ticker symbol for {company}")
        
        elif item_capitalize in COMPANIES:
            print(f"{item_capitalize} stock price is {STOCKS.get(COMPANIES[item_capitalize])}")
        
        else:
            print(f"{item} is an unknown company or an unknown ticker symbol")
 

if __name__ == '__main__':
    process_stock_queries()