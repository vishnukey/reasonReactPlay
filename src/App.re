let posts = [|
  ("Post 1", "Some content here"),
  ("This is some other title", "With some more content over here"),
  ("Last Post", "Like the bugel song?"),
|];

[@react.component]
let make = (~header) =>
  <div>
    <h1> <center> {header |> ReasonReact.string} </center> </h1>
    <hr />
    {posts
     |> Array.mapi((i, (title, content)) =>
          <Post key={"post-" ++ string_of_int(i)} id=i title content />
        )
     |> ReasonReact.array}
  </div>;
