#include "../../inc/user_actions.h"

/**
 * @brief Получает действие пользователя на основе введенного сигнала.
 *
 * Функция считывает входные данные от пользователя и определяет,
 * какое действие должно быть выполнено в зависимости от нажатой клавиши.
 * Начальное значение действия устанавливается в `Up`, а затем
 * изменяется в зависимости от распознанного ввода. Возможные
 * действия включают перемещение вниз, влево, вправо, старт,
 * завершение игры, паузу и вращение.
 *
 * @return UserAction_t Возвращает значение типа `UserAction_t`,
 *         которое соответствует действию пользователя.
 */
UserAction_t get_signal() {
  UserAction_t user_action = Up;

  int user_input = GET_USER_INPUT;

  if (user_input == KEY_DOWN)
    user_action = Down;
  else if (user_input == KEY_LEFT)
    user_action = Left;
  else if (user_input == KEY_RIGHT)
    user_action = Right;
  else if (user_input == ENTER_KEY)
    user_action = Start;
  else if (user_input == ESCAPE)
    user_action = Terminate;
  else if (user_input == BS)
    user_action = Pause;
  else if (user_input == KEY_UP)
    user_action = Action;

  return user_action;
}
