import sys

def get_stock_price():
    """Возвращает текущую цену акций компании по её названию.
    
    Функция обрабатывает аргумент командной строки (название компании),
    находит соответствующий тикер акции и выводит текущую цену из базы данных.
    
    Требования:
    - В командной строке должен быть ровно один аргумент (название компании)
    - Название компании регистронезависимо ('apple', 'APPLE' или 'Apple')
    
    Возможные результаты:
    - Цена акции с двумя знаками после запятой (если компания найдена)
    - Сообщение "Неизвестная компания" (если компании нет в базе)
    - Ничего (если аргументов нет или их слишком много)
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
    
    company_name = sys.argv[1].capitalize()  
    
    ticker = COMPANIES.get(company_name)
    
    if ticker is None:
        print("Неизвестная компания")
        return
    
    price = STOCKS.get(ticker)
    print(f"{price:.2f}")     

if __name__ == '__main__':
    get_stock_price()