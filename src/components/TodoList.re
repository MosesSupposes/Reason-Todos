[@react.component]
let make = (~todos, ~onToggle, ~onRemove) => {
  <div>
    {todos
     |> List.map(todo =>
          <TodoItem key={string_of_int(todo.id)} todo onToggle onRemove />
        )
     |> Array.of_list
     |> ReasonReact.array}
  </div>;
};
