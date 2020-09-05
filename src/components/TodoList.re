[@react.component]
let make = (~todos) => {
  <div>
    {todos
     |> List.map(todo => <TodoItem key={string_of_int(todo.id)} todo />)
     |> Array.of_list
     |> ReasonReact.array}
  </div>;
};
