type timerState =
  | Pomo
  | Short
  | Long;

let style = ReactDOMRe.Style.make(~fontFamily="serif", ());

[@react.component]
let make = (~header) => {
  let (timer, changeTimer) =
    React.useReducer((_, newTimer) => newTimer, Pomo);
  <div style>
    <h1> <center> {header |> ReasonReact.string} </center> </h1>
    <hr />
    <center>
      <Switcher>
        (
          [|
            <Switch name="Pomodoro" onClick={_ => changeTimer(Pomo)} />,
            <Switch name="Short Break" onClick={_ => changeTimer(Short)} />,
            <Switch name="Long Break" onClick={_ => changeTimer(Long)} />,
          |],
          <div>
            {switch (timer) {
             | Pomo => <Timer key="pomo-timer" time=25 />
             | Short => <Timer key="short-timer" time=5 />
             | Long => <Timer key="long-timer" time=10 />
             }}
          </div>,
        )
      </Switcher>
    </center>
  </div>;
};
