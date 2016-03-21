<GameFile>
  <PropertyGroup Name="MailTextLayer" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="2208.0000" Y="1242.0000" />
        <Children>
          <AbstractNodeData Name="Panel_mail" ActionTag="171857872" Tag="8" IconVisible="False" LeftMargin="404.0000" RightMargin="404.0000" TopMargin="121.0000" BottomMargin="121.0000" TouchEnable="True" ClipAble="False" ComboBoxIndex="2" ColorAngle="212.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="1400.0000" Y="1000.0000" />
            <Children>
              <AbstractNodeData Name="Panel_title" ActionTag="-429289430" Tag="11" IconVisible="False" LeftMargin="420.0000" RightMargin="180.0000" TopMargin="90.0000" BottomMargin="830.0000" TouchEnable="True" ClipAble="False" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" LeftEage="280" RightEage="280" TopEage="29" BottomEage="29" Scale9OriginX="280" Scale9OriginY="29" Scale9Width="290" Scale9Height="32" ctype="PanelObjectData">
                <Size X="800.0000" Y="80.0000" />
                <Children>
                  <AbstractNodeData Name="TextField_title" ActionTag="127234954" Tag="10" IconVisible="False" TopMargin="10.0000" BottomMargin="-10.0000" TouchEnable="True" FontSize="56" IsCustomSize="True" LabelText="这里是标题文本" PlaceHolderText="请输入标题，少于12个字" MaxLengthEnable="True" MaxLengthText="12" ctype="TextFieldObjectData">
                    <Size X="800.0000" Y="80.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position Y="30.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="55" G="210" B="241" />
                    <PrePosition Y="0.3750" />
                    <PreSize X="1.0000" Y="1.0000" />
                    <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="420.0000" Y="830.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3000" Y="0.8300" />
                <PreSize X="0.5714" Y="0.0800" />
                <FileData Type="Normal" Path="TextField.png" Plist="" />
                <SingleColor A="255" R="150" G="200" B="255" />
                <FirstColor A="255" R="150" G="200" B="255" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_title" ActionTag="1334265271" Tag="9" IconVisible="False" LeftMargin="221.0000" RightMargin="1050.0000" TopMargin="98.0000" BottomMargin="838.0000" FontSize="64" LabelText="标题" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="129.0000" Y="64.0000" />
                <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                <Position X="350.0000" Y="870.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2500" Y="0.8700" />
                <PreSize X="0.0921" Y="0.0640" />
                <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_playerID" ActionTag="-1975243159" Tag="12" IconVisible="False" LeftMargin="158.0000" RightMargin="1050.0000" TopMargin="248.0000" BottomMargin="688.0000" FontSize="64" LabelText="发送者" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="192.0000" Y="64.0000" />
                <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                <Position X="350.0000" Y="720.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2500" Y="0.7200" />
                <PreSize X="0.1371" Y="0.0640" />
                <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Panel_playerID" ActionTag="234017641" Tag="14" IconVisible="False" LeftMargin="420.0000" RightMargin="180.0000" TopMargin="235.0000" BottomMargin="685.0000" TouchEnable="True" ClipAble="False" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" LeftEage="280" RightEage="280" TopEage="29" BottomEage="29" Scale9OriginX="280" Scale9OriginY="29" Scale9Width="290" Scale9Height="32" ctype="PanelObjectData">
                <Size X="800.0000" Y="80.0000" />
                <Children>
                  <AbstractNodeData Name="TextField_playerID" ActionTag="2071678931" Tag="15" IconVisible="False" RightMargin="500.0000" TopMargin="10.0000" BottomMargin="-10.0000" TouchEnable="True" FontSize="56" IsCustomSize="True" LabelText="" PlaceHolderText="玩家ID" MaxLengthEnable="True" MaxLengthText="12" ctype="TextFieldObjectData">
                    <Size X="300.0000" Y="80.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position Y="30.0000" />
                    <Scale ScaleX="2.5000" ScaleY="1.0000" />
                    <CColor A="255" R="55" G="210" B="241" />
                    <PrePosition Y="0.3750" />
                    <PreSize X="0.3750" Y="1.0000" />
                    <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="420.0000" Y="685.0000" />
                <Scale ScaleX="0.4000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3000" Y="0.6850" />
                <PreSize X="0.5714" Y="0.0800" />
                <FileData Type="Normal" Path="TextField.png" Plist="" />
                <SingleColor A="255" R="150" G="200" B="255" />
                <FirstColor A="255" R="150" G="200" B="255" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Panel_text" ActionTag="1496378300" Tag="20" IconVisible="False" LeftMargin="233.3700" RightMargin="166.6300" TopMargin="379.0798" BottomMargin="120.9202" TouchEnable="True" ClipAble="True" ComboBoxIndex="2" ColorAngle="90.0000" LeftEage="280" RightEage="280" TopEage="29" BottomEage="29" Scale9OriginX="-280" Scale9OriginY="-29" Scale9Width="560" Scale9Height="58" ctype="PanelObjectData">
                <Size X="1000.0000" Y="500.0000" />
                <Children>
                  <AbstractNodeData Name="TextField_text" ActionTag="1481617296" Tag="21" IconVisible="False" TouchEnable="True" FontSize="56" IsCustomSize="True" LabelText="" PlaceHolderText="正文" MaxLengthEnable="True" MaxLengthText="12" ctype="TextFieldObjectData">
                    <Size X="1000.0000" Y="500.0000" />
                    <AnchorPoint />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="55" G="210" B="241" />
                    <PrePosition />
                    <PreSize X="1.0000" Y="1.0000" />
                    <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleY="1.0000" />
                <Position X="233.3700" Y="620.9202" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.1667" Y="0.6209" />
                <PreSize X="0.7143" Y="0.5000" />
                <SingleColor A="255" R="150" G="200" B="255" />
                <FirstColor A="255" R="231" G="242" B="255" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_send" ActionTag="1637324597" Tag="22" IconVisible="False" LeftMargin="630.0000" RightMargin="630.0000" TopMargin="910.0000" BottomMargin="10.0000" TouchEnable="True" FontSize="64" ButtonText="发送" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="99" Scale9Height="42" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="140.0000" Y="80.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="700.0000" Y="50.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.0500" />
                <PreSize X="0.1000" Y="0.0800" />
                <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_back" ActionTag="-1240432722" Tag="24" IconVisible="False" RightMargin="1260.0000" TopMargin="10.0000" BottomMargin="910.0000" TouchEnable="True" FontSize="64" ButtonText="返回" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="95" Scale9Height="42" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="140.0000" Y="80.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="70.0000" Y="950.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0500" Y="0.9500" />
                <PreSize X="0.1000" Y="0.0800" />
                <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_clothID" ActionTag="1036314989" Tag="13" IconVisible="False" LeftMargin="1255.8368" RightMargin="24.1632" TopMargin="385.9661" BottomMargin="494.0339" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="90" Scale9Height="98" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="120.0000" Y="120.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="1315.8368" Y="554.0339" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.9399" Y="0.5540" />
                <PreSize X="0.0857" Y="0.1200" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="scloth0.png" Plist="" />
                <PressedFileData Type="Normal" Path="scloth0.png" Plist="" />
                <NormalFileData Type="Normal" Path="scloth0.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_cardID" ActionTag="-40051757" Tag="14" IconVisible="False" LeftMargin="1256.1437" RightMargin="23.8563" TopMargin="534.4774" BottomMargin="345.5226" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="90" Scale9Height="98" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="120.0000" Y="120.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="1316.1437" Y="405.5226" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.9401" Y="0.4055" />
                <PreSize X="0.0857" Y="0.1200" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="scard0.png" Plist="" />
                <PressedFileData Type="Normal" Path="scard0.png" Plist="" />
                <NormalFileData Type="Normal" Path="scard0.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_money" ActionTag="-1951626177" Tag="15" IconVisible="False" LeftMargin="1254.6014" RightMargin="25.3986" TopMargin="689.2224" BottomMargin="190.7777" TouchEnable="True" FontSize="40" ButtonText="1000" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="90" Scale9Height="98" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="120.0000" Y="120.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="1314.6014" Y="250.7777" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.9390" Y="0.2508" />
                <PreSize X="0.0857" Y="0.1200" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="scard0.png" Plist="" />
                <NormalFileData Type="Normal" Path="scard0.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1104.0000" Y="621.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.6341" Y="0.8052" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="226" G="226" B="165" />
            <EndColor A="255" R="245" G="218" B="94" />
            <ColorVector ScaleX="-0.8480" ScaleY="-0.5299" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>