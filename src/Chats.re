[@react.component]
let make = () => {
  let main =
    <RouterLink className="item-row" url="chats/azure">
      {React.string("Azure")}
    </RouterLink>;

  <Window title="~Chats" main />;
};
