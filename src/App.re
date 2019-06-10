[@react.component]
let make = () => {
        <div>
                <h1>{ReasonReact.string("Hello, world")}</h1>
                <Component1 message="Hello! Click this text." />
                <Component2 greeting="Hey ho" />
        </div>
};
