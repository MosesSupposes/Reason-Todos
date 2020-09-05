let styles = {
  "input": ReactDOM.Style.make(~display="block", ~margin=".5rem 0", ()),
};

type input = {
  name: string,
  placeholder: string,
};

[@react.component]
let make = (~text: string, ~inputs: list(input)) => {
  <form>
    {inputs
     |> List.map(input =>
          <input
            style=styles##input
            name={input.name}
            placeholder={input.placeholder}
          />
        )
     |> Array.of_list
     |> ReasonReact.array}
  </form>;
};
