struct ListNode {
  int value;      // Значение в ячейке
  ListNode* prev; // Указатель на предыдущий элемент
  ListNode* next; // Указатель на следующий элемент
  
  ListNode(int value, ListNode* prev = NULL, ListNode* next = NULL) :
      value(value),
      prev(prev),
      next(next)
  { }    
};

class List {
 public:
  List() : // Конструктор по умолчанию
      frontNode(NULL),
      backNode(NULL)
  { }
  // Copy-конструктор
  List(const List& other) :
      frontNode(NULL),
      backNode(NULL)
  {
    if (!other.frontNode)
      return; // Список пустой, делать нечего.

    // Оператор new выбрасывает исключение std::bad_alloc в том случае, если ему 
    // не удаётся выделить память. Нам нужно отловить это исключение, освободить 
    // всю выделенную память и передать исключение дальше по цепочке 
    // (следующему обработчику, если он есть), чтобы показать, что наш список 
    // не удалось скопировать.
    try {
      // Создаём первую ячейку посредством стандартного copy-конструктора
      // Этот конструктор неправильно инициализирует соседей (он просто скопирует
      // указатели на соответствующие ячейки старого списка). Будем это исправлять.
      frontNode = new ListNode(*other.frontNode);
      frontNode->prev = NULL; // Это первая ячейка, у неё нет предыдущей
      frontNode->next = NULL; // Инициализируем по умолчанию
      
      // Определим переменные для итерирования по ячейкам списка
      const ListNode* otherNode = other.frontNode; // Для итерирования по старому списку
      ListNode* node = frontNode;                  // Для итерирования по новому списку
      
      // Итерируемся по всем ячейкам и копируем данные
      while (otherNode->next != NULL) { // Пока не дойдём до последней ячейки
        // Создаём новую ячейку копированием из соответствующей старой
        node->next = new ListNode(*otherNode->next);
        node->next->prev = node; // Перед созданной ячейкой находится текущая
        node->next->next = NULL; // Инициализируем по умолчанию

        // Переходим к следующей ячейке
        otherNode = otherNode->next;
        node = node->next;
      }

      backNode = node; // Инициализируем последнюю ячейку
    }
    catch(std::bad_alloc& e) {
      // Оператор new сгенерировал исключение, не удалось выделить память.
      // Для того, чтобы избежать утечек, нам нужно освобождить всю память, 
      // которую выделили.
      Clear();
      
      // Выбрасываем то же самое исключение, чтобы его поймал следующий
      // обработчик (если он есть). Тем самым мы говорим, что список
      // не удалось скопировать.
      throw;
    }
  }
  
  ~List() {
    Clear(); // Очищаем всю выделенную память
  }
  
  List& operator=(const List& other) {
    Clear(); // Сначала нужно подчистить старый список

    if (!other.frontNode)
      return *this; // Список пуст, делать нечего.

    // Аналогично copy-конструктору, проверяем, выделилась ли память.
    try {
      // Создаём первую ячейку посредством copy-конструктора
      frontNode = new ListNode(*other.frontNode);
      frontNode->prev = NULL; // Это первая ячейка, у неё нет предыдущей
      frontNode->next = NULL; // Инициализируем по умолчанию

      // Определим переменные для итерирования по ячейкам списка
      const ListNode* otherNode = other.frontNode; // Для итерирования по старому списку
      ListNode* node = frontNode;                  // Для итерирования по новому списку

      // Итерируемся по всем ячейкам и копируем данные
      while (otherNode->next != NULL) {
        // Создаём новую ячейку копированием из соответствующей старой
        node->next = new ListNode(*otherNode->next);
        node->next->prev = node; // Перед созданной ячейкой находится текущая
        node->next->next = NULL; // Инициализируем по умолчанию
        
        // Переходим к следующей ячейке
        otherNode = otherNode->next;
        node = node->next;
      }
      
      backNode = node; // Инициализируем последнюю ячейку
    }
    catch (std::bad_alloc& e) {
      // Оператор new выбросил исключение std::bad_alloc.
      // Не удалось выделить память. Очищаем всё, что выделили.
      Clear();
      // Пробрасываем исключение дальше.
      throw;
    }
    return *this;
  }
  
  void Clear() {
    // Итерируемся по циклу от первой ячейки до последней
    while (frontNode != NULL) {
      ListNode* tmp = frontNode;
      
      frontNode = frontNode->next; // Переходим к следующей ячейке
      delete tmp;                  // Удаляем ту, из которой ушли
    }
    frontNode = NULL; // Обнулим указатели, чтобы показать, что список пуст.
    backNode = NULL;
  }
  // Добавляем элемент в начало списка
  void PushFront(int value) {
    if (frontNode) {
      // Создаём ячейку в начале списка (перед frontNode)
      frontNode->prev = new ListNode(value, NULL, frontNode);
      frontNode = frontNode->prev; // Обновляем frontNode
    } else {
      frontNode = backNode = new ListNode(value); // Список был пуст
    }
  }

  void PushBack(int value) {
    if (backNode) {
      // Создаём ячейку в конце списка (после backNode)
      backNode->next = new ListNode(value, backNode);
      backNode = backNode->next;
    } else {
      frontNode = backNode = new ListNode(value); // Список был пуст
    }
  }
  
  void PopFront() {
    if (!frontNode) // Если список пуст, кидаем исключение
      throw std::out_of_range("List is empty!");
    
    ListNode* tmp = frontNode; // Сохраняем старое значение
    frontNode = frontNode->next; // Обновляем указатель на первую ячейку
    
    if (frontNode == NULL)
      backNode = NULL;  // Список состоял из одного элемента
    else
      frontNode->prev = NULL; // Эта ячейка теперь первая

    delete tmp; // Освобождаем память удалённой ячейки
  }

  void PopBack() {
    if (!backNode) // Если список пуст, кидаем исключение
      throw std::out_of_range("List is empty!");
    
    ListNode* tmp = backNode; // Сохраняем старое значение
    backNode = backNode->prev; // Обновляем указатель на последнюю ячейку
    
    if (backNode == NULL)
      frontNode = NULL;  // Список состоял из одного элемента
    else
      backNode->next = NULL; // Эта ячейка теперь последняя
    
    delete tmp;
  }
  
  // В следующих двух функциях проверок не делается.
  // Функция для получения первого элемента списка.
  int Front() const { return frontNode->value; }
  // Функция для получения последнего элемента списка.
  int Back() const { return backNode->value; }
  
  // Является ли список пустым?
  bool Empty() const {
    return frontNode == NULL;
  }

 private:
  ListNode* frontNode;  // Указатель на первую ячейку списка
  ListNode* backNode;   // Указатель на последнюю ячейку списка
  
  // Реализация прямых итераторов
 public:
  // Сначала константный итератор, который не может менять элементы списка
  class ConstIterator {
   public:
    ConstIterator(ListNode* currentNode = NULL) :
        currentNode(currentNode)
    { }

    int operator*() const { // Разыменовываем итератор
      return currentNode->value;
    }
    ConstIterator& operator++() { // Переходим к следующей ячейке
      currentNode = currentNode->next;
      return *this;
    }
    // Переходим к предыдущей ячейке. Итератор стека этого не умел.
    ConstIterator& operator--() {
      currentNode = currentNode->prev;
      return *this;
    }
    
    // Для сравнения итераторов нам необходимо определить операции сравнения
    bool operator!=(const ConstIterator& other) const {
      return currentNode != other.currentNode;
    }

    bool operator==(const ConstIterator& other) const {
      return currentNode == other.currentNode;
    }
   private:
    ListNode* currentNode;
    
    // Класс List должен иметь доступ к приватным полям для реализации методов
    // вставки и удаления элементов
    friend class List;
  };

  // Теперь определим итаратор, который может менять элементы,
  // на которые он указывает
  class Iterator {
   public:
    Iterator(ListNode* currentNode = NULL) :
        currentNode(currentNode)
    { }
    
    // Разыменовываем итератор. Метод возвращает ссылку на элемент.
    int& operator*() const {
      return currentNode->value;
    }
    Iterator& operator++() { // Переходим к следующей ячейке
      currentNode = currentNode->next;
      return *this;
    }

    // Переходим к предыдущей ячейке. Итератор стека этого не умел.
    Iterator& operator--() {
      currentNode = currentNode->prev;
      return *this;
    }
    
    // Для сравнения итераторов нам необходимо определить операцию сравнения
    bool operator!=(const Iterator& other) const {
      return currentNode != other.currentNode;
    }

    bool operator==(const Iterator& other) const {
      return currentNode == other.currentNode;
    }
   private:
    ListNode* currentNode; // Указатель на текущую ячейку

    // Класс List должен иметь доступ к приватным полям для реализации методов
    // вставки и удаления элементов.
    friend class List;
  };

  // Константный итератор на начало промежутка
  ConstIterator Begin() const { return ConstIterator(frontNode); }
  // Константный итератор на конец промежутка (указывает на элемент "после последнего")
  ConstIterator End() const { return ConstIterator(); }
  // Итератор на начало промежутка
  Iterator Begin() { return Iterator(frontNode); }
  // Итератор на конец промежутка (указывает на элемент "после последнего")
  Iterator End() { return Iterator(); }

  // Реализация обратных итераторов
 public:
  // Сначала константный итератор, который не может менять элементы списка
  class ConstReverseIterator {
   public:
    ConstReverseIterator(ListNode* currentNode = NULL) :
        currentNode(currentNode)
    { }

    int operator*() const { // Разыменовываем итератор
      return currentNode->value;
    }
    // Для обратных итераторов эти операции инвертированы
    // Переходим к следующей (то есть предыдущей) ячейке
    ConstReverseIterator& operator++() {
      currentNode = currentNode->prev;
      return *this;
    }

    // Переходим к предыдущей (то есть следующей) ячейке
    ConstReverseIterator& operator--() {
      currentNode = currentNode->next;
      return *this;
    }
    
    // Для сравнения итераторов нам необходимо определить операции сравнения
    bool operator!=(const ConstReverseIterator& other) const {
      return currentNode != other.currentNode;
    }

    bool operator==(const ConstReverseIterator& other) const {
      return currentNode == other.currentNode;
    }
   private:
    ListNode* currentNode;

    // Класс List должен иметь доступ к приватным полям для реализации методов
    // вставки и удаления элементов.
    friend class List;
  };

  // Теперь определим итаратор, который может менять элементы,
  // на которые он указывает
  class ReverseIterator {
   public:
    ReverseIterator(ListNode* currentNode = NULL) :
        currentNode(currentNode)
    { }
    
    // Разыменовываем итератор. Метод возвращает ссылку на элемент.
    int& operator*() const {
      return currentNode->value;
    }

    // Для обратных итераторов эти операции инвертированы
    // Переходим к следующей (то есть предыдущей) ячейке
    ReverseIterator& operator++() {
      currentNode = currentNode->prev;
      return *this;
    }
    
    // Переходим к предыдущей (то есть следующей) ячейке
    ReverseIterator& operator--() {
      currentNode = currentNode->next;
      return *this;
    }
    
    // Для сравнения итераторов нам необходимо определить операцию сравнения
    bool operator!=(const ReverseIterator& other) const {
      return currentNode != other.currentNode;
    }

    bool operator==(const ReverseIterator& other) const {
      return currentNode == other.currentNode;
    }
   private:
    ListNode* currentNode; // Указатель на текущую ячейку

    // Класс List должен иметь доступ к приватным полям для реализации методов
    // вставки и удаления элементов.
    friend class List;
  };

  // Для обратных итераторов следующие функции тоже инвертированы
  // Константный итератор на начало промежутка (то есть на последний элемент списка)
  ConstReverseIterator RBegin() const { return ConstReverseIterator(backNode); }
  // Константный итератор на конец промежутка (то есть на элемент "перед первым")
  ConstReverseIterator REnd() const { return ConstReverseIterator(); }
  // Итератор на начало промежутка (то есть на последний элемент списка)
  ReverseIterator RBegin() { return ReverseIterator(backNode); }
  // Итератор на конец промежутка (то есть на элемент "перед первым")
  ReverseIterator REnd() { return ReverseIterator(); }

  // Реализация методов вставки и удаления элементов
 public:
  // Вставляет элемент value на позицию pos. Возвращает итератор на вставленный элемент.
  Iterator Insert(Iterator pos, int value) {
    // Для следующей операции класс List объявлен дружественным для итераторов.
    ListNode* currentNode = pos.currentNode; // Получаем указатель на текущую ячейку.

    return Insert(currentNode, value);
  }
  
  // Можно и по константному итератору
  // Вставляет элемент value на позицию pos. Возвращает итератор на вставленный элемент.
  Iterator Insert(ConstIterator pos, int value) {
    // Для следующей операции класс List объявлен дружественным для итераторов.
    ListNode* currentNode = pos.currentNode; // Получаем указатель на текущую ячейку.
    
    return Insert(currentNode, value);
  }
  
  // Удаляет элемент, на который указывает итератор pos. Возвращает итератор на элемент,
  // который следовал за удалённым.
  Iterator Remove(Iterator pos) {
    // Для следующей операции класс List объявлен дружественным для итераторов.
    ListNode* currentNode = pos.currentNode; // Получаем указатель на текущую ячейку.
    
    return Remove(currentNode);
  }
  
  // Можно и для константного итератора
  // Удаляем элемент, на который указывает итератор pos
  Iterator Remove(ConstIterator pos) {
    // Для следующей операции класс List объявлен дружественным для итераторов.
    ListNode* currentNode = pos.currentNode; // Получаем указатель на текущую ячейку.
    
    return Remove(currentNode);
  }
 private:
  // Вставляет элемент value перед ячейкой currentNode. 
  // Возвращает итератор на вставленный элемент.
  Iterator Insert(ListNode* currentNode, int value) {
    if (currentNode == NULL) { // Если нужно вставить в конец списка
      PushBack(value);
      return Iterator(backNode);
    }
    
    if (currentNode == frontNode) { // Если нужно вставить в начало списка
      PushFront(value);
      return Iterator(frontNode);
    }
    
    // Создаём новую ячейку между предыдущей и текущей
    ListNode* insertedNode = new ListNode(value, currentNode->prev, currentNode);
    
    currentNode->prev->next = insertedNode; // После предыдущей идёт вставленная
    currentNode->prev = insertedNode;       // Вставили ячейку перед текущей
    
    return Iterator(insertedNode);  // Возвращаем итератор на вставленную ячейку
  }
  
  // Удаляет ячейку currentNode. Возвращает итератор на элемент, который 
  // следовал за удалённым.
  Iterator Remove(ListNode* currentNode) {      
    if (currentNode == NULL) // Список пуст, кидаем исключение
      throw std::out_of_range("Invalid iterator!");
    
    if (currentNode->next == NULL) { // Если удаляем из конца списка
      PopBack();
      return Iterator(NULL);
    }
    
    if (currentNode->prev == NULL) { // Если удаляем из начала списка
      PopFront();
      return Iterator(frontNode);
    }
    // Объявим для наглядности указатели на предыдущую и следующую ячейки
    ListNode* nextNode = currentNode->next;
    ListNode* prevNode = currentNode->prev;
    
    delete currentNode; // Удаляем текущую ячейку
    
    nextNode->prev = prevNode; // Перед следующей теперь стоит предыдущая.
    prevNode->next = nextNode; // А после предыдущей следующая.
    
    return Iterator(nextNode); // Возвращаем итератор на следующую ячейку.
  }
};  

