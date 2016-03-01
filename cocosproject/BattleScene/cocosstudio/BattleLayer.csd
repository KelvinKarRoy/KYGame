<GameFile>
  <PropertyGroup Name="BattleLayer" Type="Layer" ID="df56f77a-5216-4587-a690-9c3facf31085" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="151" Speed="0.4000">
        <Timeline ActionTag="-171570835" Property="ActionValue">
          <InnerActionFrame FrameIndex="0" InnerActionType="LoopAction" SingleFrameIndex="0" />
          <InnerActionFrame FrameIndex="151" InnerActionType="LoopAction" SingleFrameIndex="0" />
        </Timeline>
        <Timeline ActionTag="-171570835" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000" />
          <ScaleFrame FrameIndex="151" X="1.0000" Y="1.0000" />
        </Timeline>
        <Timeline ActionTag="-171570835" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000" />
          <ScaleFrame FrameIndex="151" X="0.0000" Y="0.0000" />
        </Timeline>
        <Timeline ActionTag="747096764" Property="ActionValue">
          <InnerActionFrame FrameIndex="0" InnerActionType="LoopAction" SingleFrameIndex="0" />
        </Timeline>
        <Timeline ActionTag="747096764" Property="Position">
          <PointFrame FrameIndex="0" X="461.1921" Y="154.1721" />
        </Timeline>
        <Timeline ActionTag="747096764" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000" />
        </Timeline>
        <Timeline ActionTag="747096764" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000" />
        </Timeline>
      </Animation>
      <ObjectData Name="Layer" ctype="GameLayerObjectData">
        <Size X="640.0000" Y="820.0000" />
        <Children>
          <AbstractNodeData Name="Battle_6" ActionTag="-912467566" ZOrder="2" Tag="1384" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" TopMargin="-0.4000" BottomMargin="180.4000" TouchEnable="True" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="0.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="640.0000" Y="640.0000" />
            <Children>
              <AbstractNodeData Name="Map_Battlemap_3" ActionTag="892432496" Tag="1385" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" ctype="GameMapObjectData">
                <Size X="640.0000" Y="640.0000" />
                <AnchorPoint />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="1.0000" Y="1.0000" />
                <FileData Type="Normal" Path="BattleScene/sandbg/sand.tmx" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="ProjectNode_Boss" ActionTag="-171570835" Tag="1386" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="209.6640" RightMargin="430.3360" TopMargin="534.4640" BottomMargin="105.5360" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.4000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Image_Monsterblood_8" ActionTag="1165287613" Tag="1537" IconVisible="False" LeftMargin="-166.0840" RightMargin="111.0840" TopMargin="-433.0795" BottomMargin="370.0795" Scale9Width="55" Scale9Height="63" ctype="ImageViewObjectData">
                    <Size X="55.0000" Y="63.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="-138.5840" Y="401.5795" />
                    <Scale ScaleX="0.8000" ScaleY="0.8000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Common/Cn17.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_Bossbloodbg_7" ActionTag="-679090096" Tag="1536" IconVisible="False" LeftMargin="-138.5867" RightMargin="-139.4133" TopMargin="-426.0795" BottomMargin="373.0795" Scale9Width="278" Scale9Height="53" ctype="ImageViewObjectData">
                    <Size X="278.0000" Y="53.0000" />
                    <Children>
                      <AbstractNodeData Name="LoadingBar_Bossblood_9" ActionTag="-1887514719" Tag="1477" IconVisible="False" LeftMargin="35.6912" RightMargin="42.3088" TopMargin="19.0858" BottomMargin="19.9142" ctype="LoadingBarObjectData">
                        <Size X="200.0000" Y="14.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="135.6912" Y="26.9142" />
                        <Scale ScaleX="1.2000" ScaleY="2.5000" />
                        <CColor A="255" R="253" G="5" B="5" />
                        <PrePosition X="0.4881" Y="0.5078" />
                        <PreSize X="0.7194" Y="0.2642" />
                        <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="0.4133" Y="399.5795" />
                    <Scale ScaleX="0.8000" ScaleY="0.8000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="BattleScene/BS14.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="209.6640" Y="105.5360" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3276" Y="0.1649" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="generalshark.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="ProjectNode_Monster" ActionTag="747096764" Tag="1478" IconVisible="True" HorizontalEdge="RightEdge" LeftMargin="461.1921" RightMargin="178.8079" TopMargin="485.8279" BottomMargin="154.1721" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.4000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Image_Monsterblood_8_0" ActionTag="1150647804" Tag="1538" IconVisible="False" LeftMargin="-118.0236" RightMargin="63.0236" TopMargin="-203.6408" BottomMargin="140.6408" Scale9Width="55" Scale9Height="63" ctype="ImageViewObjectData">
                    <Size X="55.0000" Y="63.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="-90.5236" Y="172.1408" />
                    <Scale ScaleX="0.8000" ScaleY="0.8000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Common/Cn17.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_Bossbloodbg_7_0" ActionTag="-76469448" Tag="1539" IconVisible="False" LeftMargin="-90.5293" RightMargin="-187.4707" TopMargin="-196.6408" BottomMargin="143.6408" Scale9Width="278" Scale9Height="53" ctype="ImageViewObjectData">
                    <Size X="278.0000" Y="53.0000" />
                    <Children>
                      <AbstractNodeData Name="LoadingBar_Bossblood_9_13" ActionTag="-536917136" Tag="1540" IconVisible="False" LeftMargin="35.6912" RightMargin="42.3088" TopMargin="19.0858" BottomMargin="19.9142" ctype="LoadingBarObjectData">
                        <Size X="200.0000" Y="14.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="135.6912" Y="26.9142" />
                        <Scale ScaleX="1.2000" ScaleY="2.5000" />
                        <CColor A="255" R="253" G="5" B="5" />
                        <PrePosition X="0.4881" Y="0.5078" />
                        <PreSize X="0.7194" Y="0.2642" />
                        <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="48.4707" Y="170.1408" />
                    <Scale ScaleX="0.8000" ScaleY="0.8000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="BattleScene/BS14.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="461.1921" Y="154.1721" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7206" Y="0.2409" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="tentacle.csd" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position Y="180.4000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition Y="0.2200" />
            <PreSize X="1.0000" Y="0.7805" />
            <SingleColor A="255" R="0" G="0" B="0" />
            <FirstColor A="255" R="0" G="0" B="0" />
            <EndColor A="255" R="0" G="0" B="0" />
            <ColorVector ScaleX="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Image_1" ActionTag="1423723387" Tag="6134" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" TopMargin="641.0000" BottomMargin="-1.0000" Scale9Width="640" Scale9Height="180" ctype="ImageViewObjectData">
            <Size X="640.0000" Y="180.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.0000" Y="89.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.1085" />
            <PreSize X="1.0000" Y="0.2195" />
            <FileData Type="Normal" Path="BattleScene/BS10.png" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>