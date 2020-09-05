type t = {
  id: int,
  task: string,
  completed: bool,
};

[@react.component]
let make = (~todo: t) => {
  <div className="todoItem">
    <p> {React.string(todo.task)} </p>
    <input type_="checkbox" checked={todo.completed} />
  </div>;
};
