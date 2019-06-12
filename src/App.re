let posts = [|
  ("Post 1", "Some content here"),
  ("This is some other title", "With some more content over here"),
  ("Last Post", "Like the bugel song?"),
|];

let style = ReactDOMRe.Style.make(~fontFamily="serif", ());

[@react.component]
let make = (~header) =>
  <div style>
    <h1> <center> {header |> ReasonReact.string} </center> </h1>
    <hr />
    {posts
     |> Array.mapi((id, (title, content)) =>
          <Post key={"post-" ++ string_of_int(id)} id title content />
        )
     |> ReasonReact.array}
  </div>;
