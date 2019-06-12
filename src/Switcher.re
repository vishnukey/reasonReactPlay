let style = ReactDOMRe.Style.make(~padding="1em", ());
let listStyle =
  ReactDOMRe.Style.make(~listStyle="none", ~margin="0px", ~padding="0px", ());
let itemStyle = ReactDOMRe.Style.make(~display="inline-block", ());

[@react.component]
let make = (~children) => {
  let (switches, display) = children;
  <div style>
    <ul style=listStyle>
      {switches
       |> Array.mapi((id, swich) =>
            <li key={"switch-" ++ string_of_int(id)} style=itemStyle>
              swich
            </li>
          )
       |> ReasonReact.array}
    </ul>
    display
  </div>;
};
