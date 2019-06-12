[@react.component]
let make = (~colour, ~darkColour, ~name, ~onClick) => {
  let mainStyle =
    ReactDOMRe.Style.make(
      ~borderStyle="solid",
      ~borderWidth="1px",
      ~margin="3px",
      ~backgroundColor=colour,
      ~padding="1em",
      (),
    );

  let (isHover, setHover) =
    React.useReducer((prevState, newState) => newState, false);
  let onMouseEnter = _ => setHover(true);
  let onMouseLeave = _ => setHover(false);

  let style =
    (
      isHover
        ? ReactDOMRe.Style.make(~backgroundColor=darkColour, ())
        : ReactDOMRe.Style.make(~backgroundColor=colour, ())
    )
    |> ReactDOMRe.Style.combine(mainStyle);
  <div style onMouseEnter onMouseLeave onClick>
    {name |> ReasonReact.string}
  </div>;
};
