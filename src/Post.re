let style =
  ReactDOMRe.Style.make(
    ~borderStyle="solid",
    ~borderWidth="1px",
    ~paddingLeft="3px",
    ~paddingRight="3px",
    ~paddingBottom="1px",
    ~marginBottom="2px",
    (),
  );

[@react.component]
let make = (~id: int, ~title: string, ~content: string) =>
  <div className="post" id={string_of_int(id)} style>
    <span>
      <strong> {"#" ++ string_of_int(id) |> ReasonReact.string} </strong>
      <center> <h2> {title |> ReasonReact.string} </h2> </center>
    </span>
    <div className="post-content"> {content |> ReasonReact.string} </div>
  </div>;
