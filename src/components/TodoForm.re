include TodoItem;

[@react.component]
let make = (~nextId: int, ~updateTodos) => {
  let (todoItem, setTodoItem) = React.useState(() => "");

  let handleChange = event => {
    setTodoItem(todoItem => ReactEvent.Form.target(event)##value);
    ();
  };

  let handleSubmit = event => {
    ReactEvent.Form.preventDefault(event);
    updateTodos({id: nextId, task: todoItem, completed: false});
  };

  <form onSubmit=handleSubmit>
    <input placeholder="Enter a task" value=todoItem onChange=handleChange />
  </form>;
};
