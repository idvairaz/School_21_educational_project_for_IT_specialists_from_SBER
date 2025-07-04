import sys

def get_company_and_price():
    """Возвращает название компании и текущую цену её акций по тикеру.

        Функция принимает один аргумент командной строки - тикер акции (регистронезависимый),
        ищет соответствующую компанию и выводит её название и цену акций в формате:
        "Название Цена" (цена округляется до 2 знаков после запятой).

        Требования:
        - В командной строке должен быть ровно один аргумент (тикер акции)
        - Тикер будет приведён к верхнему регистру для поиска

        Возможные результаты:
        - Название компании и цена акции, разделённые пробелом (если тикер найден)
        - "Тикер не найден" (если тикер не найден)
        - Ничего не выводится (если аргументов нет или их больше одного)
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
    
    ticker = sys.argv[1].upper()
    
    ticker_to_company = {v: k for k, v in COMPANIES.items()}
    
    company = ticker_to_company.get(ticker)
    
    if company is None:
        print("Тикер не найден")
        return
    
    price = STOCKS.get(ticker)
    print(f"{company} {price:.2f}")

if __name__ == '__main__':
    get_company_and_price()