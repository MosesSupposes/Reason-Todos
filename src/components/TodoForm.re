open TodoItem;

[@react.component]
let make =
    (~nextId: int, ~nextTodo: string, ~updateTodos, ~onInputText, ~clearInput) => {
  let handleChange = event => {
    ReactEvent.Synthetic.persist(event);
    onInputText(ReactEvent.Synthetic.target(event)##value);
  };

  let handleSubmit = event => {
    ReactEvent.Form.preventDefault(event);
    updateTodos({id: nextId, task: nextTodo, completed: false});
    Js.log("BEFORE CLEAR" ++ " " ++ nextTodo);
    clearInput();
    Js.log("AFTER CLEAR" ++ " " ++ nextTodo);
  };

  <form onSubmit=handleSubmit>
    <input placeholder="Enter a task" value=nextTodo onChange=handleChange />
  </form>;
};
