type t = {
  id: int,
  task: string,
  completed: bool,
};

[@react.component]
let make = (~todo: t) => {
  <div className="todoItem">
    <span> {React.string(todo.task)} </span>
    <input type_="checkbox" checked={todo.completed} />
  </div>;
};
