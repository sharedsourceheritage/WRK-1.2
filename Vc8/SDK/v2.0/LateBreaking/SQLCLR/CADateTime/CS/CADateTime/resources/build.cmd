resgen calendars.txt

resgen calendars.ar-SA.txt

resgen calendars.ja.txt

resgen calendars.zh-CN.txt

if not exist ar-SA/ mkdir ar-SA
if not exist ja/ mkdir ja
if not exist zh-CN/ mkdir zh-CN

al /t:lib /culture:ar-SA /embed:calendars.ar-SA.resources /out:ar-SA\CADatetime.resources.dll

al /t:lib /culture:ja /embed:calendars.ja.resources /out:ja\CADatetime.resources.dll

al /t:lib /culture:zh-CN /embed:calendars.zh-CN.resources /out:zh-CN\CADatetime.resources.dll

al /t:lib /culture:"" /embed:calendars.resources /out:CADatetime.resources.dll

