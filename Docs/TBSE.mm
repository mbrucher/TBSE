<map version="freeplane 1.2.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="TBSE" ID="ID_1723255651" CREATED="1283093380553" MODIFIED="1363609250896"><hook NAME="MapStyle">
    <conditional_styles>
        <conditional_style ACTIVE="true" LOCALIZED_STYLE_REF="AutomaticLayout.level,1" LAST="false">
            <node_level_condition VALUE="1" MATCH_CASE="false" MATCH_APPROXIMATELY="false" COMPARATION_RESULT="0" SUCCEED="true"/>
        </conditional_style>
        <conditional_style ACTIVE="true" LOCALIZED_STYLE_REF="AutomaticLayout.level,2" LAST="false">
            <node_level_condition VALUE="2" MATCH_CASE="false" MATCH_APPROXIMATELY="false" COMPARATION_RESULT="0" SUCCEED="true"/>
        </conditional_style>
        <conditional_style ACTIVE="true" LOCALIZED_STYLE_REF="AutomaticLayout.level,3" LAST="false">
            <node_level_condition VALUE="3" MATCH_CASE="false" MATCH_APPROXIMATELY="false" COMPARATION_RESULT="0" SUCCEED="true"/>
        </conditional_style>
        <conditional_style ACTIVE="true" LOCALIZED_STYLE_REF="AutomaticLayout.level,4" LAST="false">
            <node_level_condition VALUE="4" MATCH_CASE="false" MATCH_APPROXIMATELY="false" COMPARATION_RESULT="0" SUCCEED="true"/>
        </conditional_style>
    </conditional_styles>

<map_styles>
<stylenode LOCALIZED_TEXT="styles.root_node">
<stylenode LOCALIZED_TEXT="styles.predefined" POSITION="right">
<stylenode LOCALIZED_TEXT="default" MAX_WIDTH="600" COLOR="#000000" STYLE="as_parent">
<font NAME="SansSerif" SIZE="10" BOLD="false" ITALIC="false"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.details"/>
<stylenode LOCALIZED_TEXT="defaultstyle.note"/>
<stylenode LOCALIZED_TEXT="defaultstyle.floating">
<edge STYLE="hide_edge"/>
<cloud COLOR="#f0f0f0" SHAPE="ROUND_RECT"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.user-defined" POSITION="right">
<stylenode LOCALIZED_TEXT="styles.topic" COLOR="#18898b" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subtopic" COLOR="#cc3300" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subsubtopic" COLOR="#669900">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.important">
<icon BUILTIN="yes"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.AutomaticLayout" POSITION="right">
<stylenode LOCALIZED_TEXT="AutomaticLayout.level.root" COLOR="#000000">
<font SIZE="18"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,1" COLOR="#18898b">
<font SIZE="16"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,2" COLOR="#cc3300">
<font SIZE="14"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,3" COLOR="#669900">
<font SIZE="12"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,4" COLOR="#111111">
<font SIZE="10"/>
</stylenode>
</stylenode>
</stylenode>
</map_styles>
</hook>
<hook NAME="AutomaticEdgeColor" COUNTER="9"/>
<hook NAME="accessories/plugins/AutomaticLayout.properties" VALUE="ALL"/>
<node TEXT="Standards" POSITION="right" ID="ID_777310371" CREATED="1363548219174" MODIFIED="1363609250901">
<edge COLOR="#ff0000"/>
<cloud COLOR="#f0f0f0" SHAPE="ARC"/>
<node TEXT="Naming convention" ID="ID_565661685" CREATED="1363548277154" MODIFIED="1363609250910">
<node TEXT="CamelCase for classes and namespace" ID="ID_1375968716" CREATED="1363548285137" MODIFIED="1363609250920"/>
<node TEXT="function_names" ID="ID_999740542" CREATED="1363548303338" MODIFIED="1363609250922"/>
<node TEXT="variable_names" ID="ID_1079992712" CREATED="1363548309612" MODIFIED="1363609250924"/>
</node>
<node TEXT="Const whenever possible" ID="ID_353861715" CREATED="1363548329270" MODIFIED="1363609250925"/>
</node>
<node TEXT="Plugins" POSITION="right" ID="ID_1819805371" CREATED="1363548224706" MODIFIED="1363609250934">
<edge COLOR="#0000ff"/>
<cloud COLOR="#f0f0f0" SHAPE="ARC"/>
<node TEXT="GUI" ID="ID_734676766" CREATED="1363552491354" MODIFIED="1363609250940"/>
<node TEXT="AI" ID="ID_1907277368" CREATED="1363552493404" MODIFIED="1363609250945"/>
</node>
<node TEXT="GUI" POSITION="left" ID="ID_106080857" CREATED="1363548348140" MODIFIED="1363609250948">
<edge COLOR="#00ff00"/>
<cloud COLOR="#f0f0f0" SHAPE="ARC"/>
<node TEXT="2D" ID="ID_778734623" CREATED="1363548351998" MODIFIED="1363609250952">
<node TEXT="Qt" ID="ID_408738446" CREATED="1363548354827" MODIFIED="1363609250955">
<node TEXT="GraphScene" ID="ID_1230802532" CREATED="1363615670064" MODIFIED="1363618430175"/>
</node>
<node TEXT="Tiles" ID="ID_1569523169" CREATED="1363615610199" MODIFIED="1363615661550"/>
<node TEXT="Minimap" ID="ID_1929501659" CREATED="1363615723963" MODIFIED="1363615727257"/>
</node>
<node TEXT="Display" ID="ID_1958487741" CREATED="1363615620423" MODIFIED="1363615705866">
<node TEXT="Units" ID="ID_1954711108" CREATED="1363615706932" MODIFIED="1363615709415"/>
<node TEXT="Buildings" ID="ID_614640103" CREATED="1363615710449" MODIFIED="1363615713454"/>
</node>
</node>
<node TEXT="AI" POSITION="left" ID="ID_372249438" CREATED="1363548359822" MODIFIED="1363609250956">
<edge COLOR="#ff00ff"/>
<cloud COLOR="#f0f0f0" SHAPE="ARC"/>
</node>
<node TEXT="Concepts" POSITION="right" ID="ID_1329675284" CREATED="1363548474677" MODIFIED="1363609250959">
<edge COLOR="#00ffff"/>
<cloud COLOR="#f0f0f0" SHAPE="ARC"/>
<node TEXT="Maps" ID="ID_1588400702" CREATED="1363548563563" MODIFIED="1363609250964">
<node TEXT="Hexagonal maps" ID="ID_516828778" CREATED="1363548479095" MODIFIED="1363609250962"/>
<node TEXT="Different tiles" ID="ID_1653683784" CREATED="1363609576494" MODIFIED="1363609583098"/>
</node>
<node TEXT="Resources" ID="ID_784426964" CREATED="1363615898403" MODIFIED="1363615901000"/>
<node TEXT="Units" ID="ID_1095827753" CREATED="1363548546869" MODIFIED="1363609250963">
<node TEXT="Evolving units" ID="ID_187162190" CREATED="1363550995267" MODIFIED="1363615640979"/>
<node TEXT="Properties for units" ID="ID_1412204509" CREATED="1363609024892" MODIFIED="1363615649501"/>
<node TEXT="Limited ammunition" ID="ID_1202385006" CREATED="1363615914507" MODIFIED="1363615921336"/>
<node TEXT="Limited gas" ID="ID_810491706" CREATED="1363615927644" MODIFIED="1363615936864"/>
</node>
<node TEXT="Research" ID="ID_667425062" CREATED="1363615903782" MODIFIED="1363615906974"/>
<node TEXT="Buildings" ID="ID_432443546" CREATED="1363609552967" MODIFIED="1363609556193">
<node TEXT="Resources to build" ID="ID_1970726407" CREATED="1363615945685" MODIFIED="1363615951162"/>
<node TEXT="Energy to function" ID="ID_1907102947" CREATED="1363615952013" MODIFIED="1363615967409"/>
<node TEXT="Storage" ID="ID_1469135294" CREATED="1363615958901" MODIFIED="1363615975377"/>
</node>
<node TEXT="Campaigns" ID="ID_124942231" CREATED="1363548565893" MODIFIED="1363609250965"/>
</node>
<node TEXT="Tools" POSITION="left" ID="ID_969653733" CREATED="1363548610348" MODIFIED="1363609250966">
<edge COLOR="#ffff00"/>
<cloud COLOR="#f0f0f0" SHAPE="ARC"/>
<node TEXT="Map editor" LOCALIZED_STYLE_REF="styles.subsubtopic" ID="ID_551518382" CREATED="1363548617418" MODIFIED="1363552866845"/>
<node TEXT="Unit editor" LOCALIZED_STYLE_REF="styles.subsubtopic" ID="ID_1375566481" CREATED="1363548622406" MODIFIED="1363552866846"/>
</node>
<node TEXT="Scripting" POSITION="right" ID="ID_1426975825" CREATED="1363548631796" MODIFIED="1363609250967">
<edge COLOR="#00007c"/>
<cloud COLOR="#f0f0f0" SHAPE="ARC"/>
<node TEXT="Python" LOCALIZED_STYLE_REF="styles.subsubtopic" ID="ID_182732977" CREATED="1363548638448" MODIFIED="1363552866847"/>
<node TEXT="AI" LOCALIZED_STYLE_REF="styles.subsubtopic" ID="ID_1982139838" CREATED="1363552436791" MODIFIED="1363552866848"/>
<node TEXT="Some player actions" LOCALIZED_STYLE_REF="styles.subsubtopic" ID="ID_1142066501" CREATED="1363552447869" MODIFIED="1363552866849"/>
<node TEXT="Maps" LOCALIZED_STYLE_REF="styles.subsubtopic" ID="ID_746154299" CREATED="1363552440279" MODIFIED="1363552866850"/>
</node>
</node>
</map>
