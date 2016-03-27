<GameFile>
  <PropertyGroup Name="HomeScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="2208.0000" Y="1242.0000" />
        <Children>
          <AbstractNodeData Name="Button_exit" ActionTag="-1978724858" Tag="43" IconVisible="False" LeftMargin="1928.1621" RightMargin="179.8379" TopMargin="110.4402" BottomMargin="1031.5598" TouchEnable="True" FontSize="48" ButtonText="登出" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="6" BottomEage="6" Scale9OriginX="15" Scale9OriginY="6" Scale9Width="61" Scale9Height="36" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="100.0000" Y="100.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1978.1621" Y="1081.5598" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8959" Y="0.8708" />
            <PreSize X="0.0453" Y="0.0805" />
            <FontResource Type="Normal" Path="wending.TTF" Plist="" />
            <TextColor A="255" R="138" G="138" B="141" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="LoadingBar_exp" ActionTag="924996499" Alpha="181" Tag="24" IconVisible="False" TopMargin="1232.0000" ctype="LoadingBarObjectData">
            <Size X="2208.0000" Y="10.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="1104.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="232" G="242" B="241" />
            <PrePosition X="0.5000" />
            <PreSize X="1.0000" Y="0.0081" />
            <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="Panel_info" ActionTag="1363986417" Tag="15" IconVisible="False" RightMargin="1808.0000" BottomMargin="892.0000" TouchEnable="True" ClipAble="False" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="400.0000" Y="350.0000" />
            <Children>
              <AbstractNodeData Name="Text_name" ActionTag="-1547436080" Alpha="229" Tag="16" IconVisible="False" LeftMargin="20.0000" RightMargin="248.0000" TopMargin="25.0000" BottomMargin="275.0000" FontSize="50" LabelText="昵称：" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="132.0000" Y="50.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="20.0000" Y="300.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0500" Y="0.8571" />
                <PreSize X="0.3300" Y="0.1429" />
                <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_level" ActionTag="-188705152" Alpha="229" Tag="17" IconVisible="False" LeftMargin="20.0000" RightMargin="248.0000" TopMargin="75.0000" BottomMargin="225.0000" FontSize="50" LabelText="等级：" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="132.0000" Y="50.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="20.0000" Y="250.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0500" Y="0.7143" />
                <PreSize X="0.3300" Y="0.1429" />
                <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_exp" ActionTag="1067603517" Alpha="229" Tag="18" IconVisible="False" LeftMargin="20.0000" RightMargin="198.0000" TopMargin="125.0000" BottomMargin="175.0000" FontSize="50" LabelText="经验值：" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="182.0000" Y="50.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="20.0000" Y="200.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0500" Y="0.5714" />
                <PreSize X="0.4550" Y="0.1429" />
                <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_VP" ActionTag="-1909095977" Alpha="229" Tag="19" IconVisible="False" LeftMargin="20.0000" RightMargin="198.0000" TopMargin="175.0000" BottomMargin="125.0000" FontSize="50" LabelText="饥饿度：" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="182.0000" Y="50.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="20.0000" Y="150.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0500" Y="0.4286" />
                <PreSize X="0.4550" Y="0.1429" />
                <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_money" ActionTag="-666280880" Alpha="229" Tag="20" IconVisible="False" LeftMargin="20.0000" RightMargin="198.0000" TopMargin="225.0000" BottomMargin="75.0000" FontSize="50" LabelText="游戏币：" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="182.0000" Y="50.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="20.0000" Y="100.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0500" Y="0.2857" />
                <PreSize X="0.4550" Y="0.1429" />
                <FontResource Type="Normal" Path="wending.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleY="1.0000" />
            <Position Y="1242.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition Y="1.0000" />
            <PreSize X="0.1812" Y="0.2818" />
            <SingleColor A="255" R="255" G="255" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>