README.txt
פרויקט הגשה oop1 – Save The King –
שמות מגישים
יעקב חיימוף – 318528510
רועי בן עזרא – 206123994 

תיאור הפרויקט:
משחק מונחה שעון שמשלב ירושה ופולימורפיזם בעזרת גרפיקה. 

תיאור משחקיות:
במשחק ניתן לזוז עם השחקן בעזרת מקשי החיצים של המקלדת. כדי להחליף את הדמות שמשחקת יש ללחוץ על המקש p. 
תנועת השחקן מתאפשרת לו בהתאם לדמות ולמיקום אשר בה היא נמצאת.
במשחק יש ארבע דמויות: מלך, מכשף, לוחם וגנב.
מטרת המשחק היא להביא את המלך לכס המלכות.
בלוח המשחק יופיעו האריחים ועצמים הבאים:
חומה, שער, אש, מפתח, אורק, תא טלפורט, מתנות וכס המלכות.
כמו כן יופיעו גמדים אשר יפריעו לתנועת הדמויות בלוח.

יכולות הדמויות:
מלך. כאמור המלך עולה כס המלכות ובכך השלב נגמר. המלך יכול ללכת על מפתח אך לא לאסוף אותו,
להיכנס לטלפורט ולעבור.
מכשף. המכשף מכבה את האש, המכשף יכול ללכת על מפתח אך לא לאסוף אותו, יכול לעמוד על תא טלפורט אך לא לעבור דרכו.
לוחם. נלחם באורק ומנצח ונופל מהאורק מפתח, אך הוא לא יכול לקחת אותו. יכול להיכנס לתא טלפורט ולעבור.
גנב. הגנב לוקח מפתח. כאשר יש לו מפתח יכול לפתוח את השער. הגנב לא יכול להיות עם יותר ממפתח אחד ברגע נתון. 

אף דמות אינה יכולה לעמוד על חומה.

ניתן לאסוף מתנות במשחק שמקנות אחד מהבונוסים:
•	תוספת זמן בשלב.
•	החסרת זמן מהשלב.
•	העפת הגמדים מהלוח.

תיכון (design):

מחלקת controller:
המחלקה הראשית אשר תפקידה לנהל את התנהלות המשחק.
המחלקה מנהלת את שלבי המשחק וכן את האירועים במשחק.
מחזיקה m_data אשר מקבל איזה שחקן פעיל, ואת תזוזת השחקן בלוח. 
מחזיקה WindowManager אשר מנהל את חלונות המשחק.
מנהלת את שעון המשחק.

מחלקת WindowManager:
מנהלת את החלונות במשחק, את הטקסטים שמוצגים בחלונות ואת הסאונדים של המשחק.
ניתן להפסיק את הסאונד של המשחק על ידי לחיצה על אייקון הסאונד. כמו כן ניתן גם להפסיק את השלב על ידי לחיצה על אייקון ה״pause״.

מחלקת MenuWinow:
מנהלת את חלון התפריט בתחילת המשחק.
ניתן לבחור בחלון הסברים, משחק, ויציאה מהמשחק.

מחלקת HelpWindow:
מנהלת את חלון ההסברים.
בחלון יש כפתור “Back” על מנת לחזור לתפריט.

מחלקת SelectLevel:
מנהלת את חלון בחירת השלב.
ניתן לבחור שלב מהקל לקשה.

מחלקת PlayWindow:
מנהלת את חלון המשחק, רקעי השלבים, הטקסטים בפסילת שלב וכן בניצחון.
מנהלת את הסאונד של המשחק, מחזיקה בשני כפתורים. כפתור “mute” וכפתור “pause”.
מציגה את תצוגת המידע אודות השלב, שלב, זמן, שחקן פעיל והאם לגנב יש מפתח.

מחלקת board:
קוראת את השלב והזמן שלו מקובץ הקלט board.txt, ושולחת את השלב והזמן למחלקת data  אשר שם יותחלו האובייקטים של data וישלח הזמן למחלקת controller.
המחלקה מחזיקה מצביע לקובץ הטקסט ווקטורים אשר שומרים את השלבים.

מחלקת data:
מנהלת את כל מה שקשור לווקטורים של האובייקטים.
היא מאתחלת את האובייקטים שלה, מנהלת את התזוזה, התנגשויות ומציגה אותם בלוח המשחק.
מחברת בין תאי הטלפורטים על ידי כך שמגרילה לכל תא לאיזה תא יישלח (מלבד עצמו) עת דמות תעמוד עליו. 
המחלקה מחזיקה וקטורים unique ptr  של players, dwarfs, teleports.
מחזיקה m_board כדי לקרוא לפונקציית הגישה של board כדי שתקרא את השלב ותשלח בחזרה לdata לאתחל את האובייקטים שלה.

מחלקת resources:
מנהלת את העזרים החיצוניים של המשחק התמונות וסאונדים.
המחלקה ממושת בעזרת design pattern שנקרא singleton, כך שיהיה ניתן לגשת לתמונות ולסאונדים בעזרת מצביע לאותם עזרים הנדרשים.

מחלקת gameObjects:
מחלקת בסיס אבסטרקטית של המחלקות MovingObjects ו staticObjects. תפקיד המחלקה הוא להחזיק ולתחזק את התכונות אשר המחלקות שיורשות ממנו משתמשות בהן.
כגון drawShape, setSprite, וכן בכל הפונקציות של double dispatch. 
מחזיקה בsf::Sprite.

מחלקת MovingObjects:
מחלקת ביניים אבסטרקטית שתפקידה הוא להחזיק ולתחזק את התכונות של האובייקטים שנעים בלוח.
כגון פונקציית move והאנימציה של הדמויות והגמדים. כמו כן מנהלת את רוב ההתנגשויות של השחקנים שנעים בלוח מלבד מקרים אשר בהם דמות מנהלת מקרה אשר מיוחד לה.
מחזיקה בsf::Vector2f ששומר את המיקום הקודם של דמות עת צריך להחזיר אותה אחורה במקרה בו היא נעה למקום שלא בסט היכולות שלה.
מחלקות שיורשות מ-movingObjects: Player, Enemy.

מחלקת Player:
מחלקת ביניים אשר דמויות המשחק יורשות ממנה.
מחלקות יורשות: kingObject, mageObject, warriorObject, thiefObject.

	מחלקת kingObject:
	המחלקה מייצגת את המלך, מטפלת במקרה בו המלך עולה על כס המלכות.
	
	מחלקת mageObject:
	המחלקה שמייצגת את המכשף, מטפלת במקרה בו המכשף עולה על האש.
	מחלקת warriorObject:
	המחלקת שמייצגת את הלוחם, מטפלת במקרה בו הלוחם עומד על אורק.
	
	מחלקת thiefObject:
	המחלקה שמייצגת את הגנב, מטלפת במקרה בו הגנב עומד על מפתח ושער.



מחלקת Enemy:
מחלקת ביניים אשר הגמדים יורשים ממנה. מנהלת ומתחזקת תכונות של אוייבים כגון isDead.
מחלקות יורשות: dwarfsObject.

	מחלקת dwarfsObject:
	המחלקה שמייצגת את הגמדים. מנהלת את התנועה האקראית של הגמדים בלוח.

מחלקת staticObjects:
מחלקת ביניים אשר מנהלת את תכונות האריחים והעצמים בלוח המשחק.
מחזיקה בתכונות כגון isDead, ובהתנגשויות של הדמויות באריחים ועצמים.
מחלקות יורשות: wallObject, crownObject, fireObject, gateObject, keyObject, monsterObject, teleportObject, timeGiftObject, removeDwarfsObject.

	מחלקת wallObject:
	המחלקה שמייצגת את החומה.

מחלקת crownObject:
	המחלקה שמייצגת את כס המלכות.

מחלקת fireObject:
	המחלקה שמייצגת את האש.

מחלקת gateObject:
	המחלקה שמייצגת את השער.

מחלקת keyObject:
	המחלקה שמייצגת את המפתח.

מחלקת monsterObject:
	המחלקה שמייצגת את האורק.

מחלקת teleportObject:
	המחלקה שמייצגת את תאי הטלפורט. 
	מחזיקה בsf::Vector2f אשר שומר את המיקום של תא הטלפורט של הצמד שלו.

	 

מחלקת timeGiftObject:
	המחלקה שמייצגת את מתנת הזמן.

מחלקת removeDwarfsObject:
	המחלקה שמייצגת את המתנה שמסלקת את הגמדים מהלוח.


פורמט קובץ השלב:

שם הקובץ יהיה board.txt
גבולות השלב יהיו חומה אשר תוחמת את הלוח.
בשורה הראשונה יופיע הזמן הנדרש עבור המפה.
לאחר מכן תופיע המפה של השלב.
בין שלב לשלב תפריד שורה ריקה.

הסימנים של האובייקטים על המסך הם:
מלך - K
מכשף - T
לוחם - W 
גנב -T
גמד -^
מתנת זמן -$
מתנה שמסלקת גמדים -~
חומה -=
כס מלכות -@
אש -*
אורק -!
טלפורט -X
שער -#
מפתח -F

רשימת הקבצים:

Controller.cpp מנהל את המשחק.
WindowManager.cpp מנהלת את החלונות.
helpWindow.cpp מנהלת את חלון ההסברים.
menuWindow.cpp מנהלת את תפריט בתחילת המשחק.
selctLevel.cpp מנהלת את בחירת השלבים.
playWindow.cpp מנהלת את חלון המשחק. 
Board.cpp קוראת את קובץ הטקסט ומחזיקה השלבים.
data.cpp מנהלת את האובייקטים של המשחק.
resources.cpp מנהלת את העזרים החיצוניים של המשחק כגון תמונות וסאונדים.
MovingObjects.cpp מנהלת את השחקנים שנעים.
Player.cpp מחלקת ביניים לדמויות.
King.cpp מייצגת את המלך.
Mage.cpp  מייצגת את המכשף.
Warrior.cpp מייצגת את הלוחם.
Thief.cpp מייצגת את הגנב.
Enemy.cpp מחלקת ביניים לגמדים.
Dwarf.cpp מייצגת את הגמדים.
staticObjects.cpp מחלקת ביניים לאובייקטים הסטטיים.
Wall.cpp מייצגת את החומה.
Crown.cpp מייצגת את הכתר במשחק.
Fire.cpp מייצגת את האש.
Gate.cpp מייצגת את השער.
Key.cpp מייצגת את המפתח.
Monster.cpp מייצגת את האורק.
Teleport.cpp מייצגת את הטלפורט.
Gifts.cpp מייצגת את מתנת הזמן במשחק.
removeDwarfs.cpp מייצגת את מתנת הסרת הגמדים מהלוח במשחק.

מבנה נתונים:
מחלקת data  מחזיקה בווקטורים מסוג unique ptr עבור הדמויות, גמדים ותאי הטלפורט.

אלגוריתם לציון:
אובייקט הטלפורט מחזיק את המיקום ואת האינדקס במערך של תא הטלפורט שהוא הצמד שלו,
וכן מחזיק במשתנה בוליאני שמציין אם התא פתוח.
עת דמות מתנגשת בתא טלפורט נבדקים שני דברים.
1.	האם תא הטלפורט פתוח.
2.	האם אין דמות אחרת במשחק אשר נמצאת על תא הטלפורט שהוא הצמד של הנוכחי.
במידה ושני התנאים התקיימו הדמות נשלחת למיקום של הצמד של תא הטלפורט הנוכחי שבו עלתה.
הטלפורט אשר הוא הצמד שלו ננעל בעזרת האינדקס שלו ששמור אצלו, דאטה תשמור את האינדקס של הטלפורט אשר ננעל. כעת לאחר התזוזה של השחקן תבדוק האם השחקן עדיין נמצא על תא הטלפורט הנעול , כל עוד הוא נמצא על התא הנעול, ההתנגשות לא תיבדק ובכך נמנע מצב אשר בו הדמות תיבדק תתקע על התא כיוון שההתנגשות יכלה להיבדק לנצח.

באגים ידועים:

הערות:

1.	לפני המשחק ניתן לבחור באיזה שלב רוצים להתחיל על פי דרגת קושי.
2.	תא טלפורט נעול, כלומר דמות אחרת נמצאת על התא אשר הוא שולח אליו, לא יתפקד במצב כזה.
3.	ניתן ללחוץ על כפתור “pause” כדי לעצור את המשחק.
4.	ניתן ללחוץ על כתפור “mute” אשר משתיק את מוסיקת המשחק.
5.	במידה והשחקן עלה על מתנה תוספת זמן יוגרל כמות הזמן שתוסף או לחלופין תורד מהשלב הנוכחי.
6.	יש שלושה שלבים למשחק.
7.	יש לחתום את השלב ב= אשר יהווה כגבולות המשחק.
8.	במידה והדמות התנגשה בעצם בלוח יושמע סאונד מתאים לפי המקרה.
9.	יש אנימציה לדמויות הנעות, וכן לחלק מין העצמים הסטטיים.