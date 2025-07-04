import sys

"""Списки клиентов"""
clients = ['andrew@gmail.com', 'jessica@gmail.com', 'ted@mosby.com',
           'john@snow.is', 'bill_gates@live.com', 'mark@facebook.com',
           'elon@paypal.com', 'jessica@gmail.com']
participants = ['walter@heisenberg.com', 'vasily@mail.ru',
                'pinkman@yo.org', 'jessica@gmail.com', 'elon@paypal.com',
                'pinkman@yo.org', 'mr@robot.gov', 'eleven@yahoo.com']
recipients = ['andrew@gmail.com', 'jessica@gmail.com', 'john@snow.is']

clients_set = set(clients)
participants_set = set(participants)
recipients_set = set(recipients)

def get_call_center_list():
    """Выводит список клиентов, которые ещё не получили рекламное письмо"""
    return clients_set - recipients_set

def get_potential_clients():
    """Выводит список участников, которые не являются клиентами"""
    return participants_set - clients_set

def get_loyalty_program():
    """Выводит список клиентов, которые не участвовали в мероприятии"""
    return clients_set - participants_set

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Необходимо указать задачу, которую надо выполнить "
        "(python3 marketing.py <call_center>, <potential_clients> или <loyalty_program>)")
        sys.exit(1)
    
    task = sys.argv[1].lower()
    
    try:
        if task == 'call_center':
            result = get_call_center_list()
        elif task == 'potential_clients':
            result = get_potential_clients()
        elif task == 'loyalty_program':
            result = get_loyalty_program()
        else:
            raise ValueError("Такой задачи не существует")
        
        for email in result:
            print(email)
            
    except ValueError as e:
        print(f"Ошибка: {e}")
        sys.exit(1)