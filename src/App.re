open TodoItem;
type state = {
  todoItems: list(TodoItem.t),
  nextTodo: string,
  nextId: int,
};

type action =
  | AddTodoItem(TodoItem.t)
  | InputText(string)
  | ToggleComplete(int)
  | RemoveItem(int)
  | ClearInput;

let initialState: state = {todoItems: [], nextTodo: "", nextId: 0};

let reducer = (state, action) =>
  switch (action) {
  | AddTodoItem(todoItem) => {
      ...state,
      nextId: state.nextId + 1,
      todoItems: [todoItem, ...state.todoItems],
    }
  | InputText(newText) => {...state, nextTodo: newText}
  | ToggleComplete(id) => {
      ...state,
      todoItems:
        List.map(
          todo =>
            if (todo.id == id) {
              {...todo, completed: !todo.completed};
            } else {
              todo;
            },
          state.todoItems,
        ),
    }
  | RemoveItem(id) => {
      ...state,
      todoItems: List.filter(todo => todo.id != id, state.todoItems),
    }
  | ClearInput => {...state, nextTodo: ""}
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <main>
    <TodoForm
      nextId={state.nextId}
      nextTodo={state.nextTodo}
      updateTodos={newTodoItem => dispatch(AddTodoItem(newTodoItem))}
      onInputText={newText => dispatch(InputText(newText))}
      clearInput={() => dispatch(ClearInput)}
    />
    <TodoList
      todos={state.todoItems}
      onToggle={id => dispatch(ToggleComplete(id))}
      onRemove={id => dispatch(RemoveItem(id))}
    />
  </main>;
};
