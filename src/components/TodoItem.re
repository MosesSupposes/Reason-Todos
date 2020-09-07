type t = {
  id: int,
  task: string,
  completed: bool,
};

[@react.component]
let make = (~todo: t, ~onToggle, ~onRemove) => {
  <div className={todo.completed ? "todoItem completed" : "todoItem"}>
    <span> {React.string(todo.task)} </span>
    <input
      type_="checkbox"
      checked={todo.completed}
      onChange={_ => {onToggle(todo.id)}}
    />
    <button onClick={_ => onRemove(todo.id)}> {React.string("X")} </button>
  </div>;
};
