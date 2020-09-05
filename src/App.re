type state = {
  todoItems: list(TodoItem.t),
  nextTodo: string,
  nextId: int,
};

type action =
  | AddTodoItem(TodoItem.t);

let initialState: state = {
  todoItems: [
    {id: 0, task: "Debug this app", completed: false},
    {id: 1, task: "Go clothes shopping", completed: false},
  ],
  nextTodo: "",
  nextId: 2,
};

let reducer = (state, action) =>
  switch (action) {
  | AddTodoItem(todoItem) => {
      ...state,
      nextId: state.nextId + 1,
      todoItems: List.append([todoItem], state.todoItems),
    }
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <main>
    <TodoForm
      nextId={state.nextId}
      updateTodos={newTodoItem => dispatch(AddTodoItem(newTodoItem))}
    />
    <TodoList todos={state.todoItems} />
  </main>;
};
