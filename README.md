# 🏦 Professional Bank Management System

نظام إدارة بنكي (Console Application) مبني بلغة **C++** باستخدام مبادئ البرمجة الكائنية (OOP)، بيوفر إدارة كاملة للعملاء والمستخدمين والعمليات المالية الأساسية، بالإضافة إلى **نظام متكامل لإدارة العملات وتحويلها (Currency Exchange)**.

---

## 📋 نظرة عامة

المشروع ده عبارة عن Bank Management System شغال من خلال الـ Console، بيحاكي عمليات البنوك الحقيقية زي إضافة العملاء، الإيداع، السحب، وتحويل الأموال، وإدارة المستخدمين والصلاحيات.

ومع تطور المشروع، تمت إضافة **Currency Exchange Module** كامتداد جديد للنظام، بحيث يقدر المستخدم يدير العملات وأسعار الصرف ويعمل عمليات تحويل بين العملات المختلفة.

المشروع بيعتمد على مبادئ **Object-Oriented Programming** مع فصل الـ Screens عن الـ Business Logic، وتنظيم كل جزء من النظام في Classes مسؤولة عن وظيفتها.

---

## ✨ المميزات الحالية

* **إدارة العملاء (Clients Management)**

  * إضافة، تعديل، حذف، والبحث عن عميل.
  * عرض قائمة كاملة بكل العملاء.
* **إدارة المستخدمين (Users Management)**

  * إضافة وتعديل وحذف المستخدمين.
  * نظام تسجيل دخول (Login) بحماية إضافية.
* **العمليات المالية (Transactions)**

  * إيداع (Deposit) وسحب (Withdraw) من حساب العميل.
  * **تحويل أموال بين الحسابات (Transfer)** مع تسجيل كامل لكل عملية تحويل (Transfer Log + شاشة عرض مخصصة).
  * عرض إجمالي الأرصدة (Total Balances).
* **الأمان (Security)**

  * **Password Hashing** بدل التخزين الصريح.
  * **قفل الحساب بعد محاولات دخول فاشلة (Login Lockout)** — بلوك تلقائي بعد 3 محاولات باسورد خاطئة.
* **نظام تسجيل الأحداث (Logging System)**

  * تسجيل العمليات المهمة (دخول، خروج، تعديلات، تحويلات) بالتاريخ والوقت.
* **نظام الصلاحيات (Permissions System)**

  * تحكم دقيق فيما يقدر كل مستخدم يعمله حسب صلاحياته.
* **Currency Exchange**

  * عرض قائمة العملات المتاحة.
  * البحث عن عملة معينة.
  * تحديث الـ Exchange Rate.
  * Currency Exchange Calculator.
  * تحويل قيمة من عملة إلى عملة أخرى.
  * تخزين بيانات العملات بشكل منفصل في `Currencies.txt`.
  * شاشة رئيسية مستقلة للـ Currency Exchange.
* **تصميم Object-Oriented**

  * Inheritance بين `clsPerson` و `clsBankClient` / `clsUser`.
  * فصل الشاشات (Screens) عن منطق البيانات (Business Logic).
  * استخدام `enum` بدل الـ Magic Numbers لحالات الحفظ والوضع.
  * تقسيم أجزاء النظام إلى Classes مستقلة تسهّل إضافة Features جديدة.

---

## 💱 Currency Exchange System

تمت إضافة **Currency Exchange Module** كامتداد جديد للمشروع، بهدف توسيع وظائف الـ Bank Management System وإضافة التعامل مع العملات وأسعار الصرف.

### الوظائف المتاحة:

* **Currencies List**

  * عرض جميع العملات الموجودة في النظام.
* **Find Currency**

  * البحث عن عملة معينة وعرض بياناتها.
* **Update Currency**

  * تعديل بيانات العملة وتحديث الـ Exchange Rate.
* **Currency Calculator**

  * اختيار العملة المصدر (From Currency).
  * اختيار العملة المستهدفة (To Currency).
  * إدخال المبلغ.
  * حساب القيمة بعد التحويل.
* **Currency Exchange Main Screen**

  * شاشة رئيسية مخصصة للوصول إلى جميع وظائف الـ Currency Exchange.

بيانات العملات يتم تخزينها في:

```text
Currencies.txt
```

وبكده تم فصل بيانات العملات عن بيانات العملاء والمستخدمين والـ Logs الموجودة في باقي النظام.

---

## 🗂️ هيكل المشروع

| **الملف**                                     | **الوظيفة**                                       |
| --------------------------------------------- | ------------------------------------------------- |
| `clsPerson.h/.cpp`                            | الكلاس الأساسي المشترك (الاسم، الإيميل، التليفون) |
| `clsBankClient.h`                             | كلاس العميل وكل عمليات الحساب البنكي              |
| `clsUser.h`                                   | كلاس المستخدم (الموظف/الأدمن)                     |
| `clsCurrency.h`                               | كلاس العملة وإدارة بيانات وأسعار الصرف            |
| `clsLoginScreen.h`                            | شاشة تسجيل الدخول                                 |
| `clsMainScreen.h`                             | الشاشة الرئيسية والتنقل بين الأقسام               |
| `clsClientListScreen.h`                       | عرض قائمة العملاء                                 |
| `clsAddNewClientScreen.h`                     | إضافة عميل جديد                                   |
| `clsUpdateClientScreen.h`                     | تعديل بيانات عميل                                 |
| `clsDeleteClientScreen.h`                     | حذف عميل                                          |
| `clsFindClientScreen.h`                       | البحث عن عميل                                     |
| `clsDepositScreen.h` / `clsWithdrawScreen.h`  | عمليات الإيداع والسحب                             |
| `clsTotalBalancesScreen.h/.cpp`               | عرض إجمالي أرصدة كل العملاء                       |
| `clsManageUsersScreen.h`                      | إدارة المستخدمين                                  |
| `clsTransferScreen.h`                         | تحويل الأموال بين الحسابات                        |
| `clsTransferLog.h` / `clsTransferLogScreen.h` | تسجيل وعرض عمليات التحويل                         |
| `clsCurrencyExchangeMainScreen.h`             | الشاشة الرئيسية لنظام Currency Exchange           |
| `clsCurrenciesListScreen.h`                   | عرض قائمة العملات                                 |
| `clsFindCurrencyScreen.h`                     | البحث عن عملة                                     |
| `clsUpdateCurrencyScreen.h`                   | تحديث بيانات وسعر العملة                          |
| `clsCurrecnyCalculatorScreen.h`               | Currency Exchange Calculator                      |
| `clsLog.h`                                    | تسجيل الأحداث العامة (Login, Logout, Actions...)  |
| `clsEncryptionUtil.h`                         | Password Hashing                                  |
| `clsInputValidate.h`                          | التحقق من صحة المدخلات                            |
| `clsString.h` / `clsUtil.h`                   | أدوات مساعدة عامة (String handling & Utilities)   |
| `Clients.txt` / `Users.txt`                   | تخزين بيانات العملاء والمستخدمين                  |
| `Currencies.txt`                              | تخزين بيانات العملات وأسعار الصرف                 |
| `Logs.txt` / `TransferLog.txt`                | ملفات تسجيل الأحداث والتحويلات                    |

---

## ⚙️ متطلبات التشغيل

* Windows + Visual Studio (2019 أو أحدث يُفضّل).
* المشروع بيستخدم ملفات `.vcxproj` الخاصة بـ Visual Studio.

### طريقة التشغيل

1. حمّل أو اعمل Clone للريبو:

```bash
git clone https://github.com/TarekMahmoudSayed/Professional-Bank-Management-System.git
```

2. افتح ملف `Bank System Project.vcxproj` في Visual Studio.
3. اعمل Build ثم Run (`F5`).

---

## 🔒 ملاحظة أمنية

بعد التحديثات الأخيرة، لم تعد كلمات المرور (PIN Codes) تُخزَّن كنص صريح؛ يتم الآن استخدام **Hashing** قبل الحفظ، بالإضافة إلى نظام قفل تلقائي للحساب بعد محاولات دخول فاشلة متكررة.

رغم ذلك، يظل التخزين على شكل ملفات نصية (Flat Files) غير مناسب لبيئة إنتاج حقيقية على نطاق واسع، والانتقال لقاعدة بيانات حقيقية (SQL/NoSQL) يظل خطوة مستقبلية.

---

## 🗺️ خارطة الطريق (Roadmap)

### ✅ تم إنجازه

#### v2.0 — Security & Banking Features

* **Password Hashing** — استخدام Hashing بدل التخزين الصريح.
* **Logging System** — تسجيل العمليات المهمة بالتاريخ والوقت.
* **Login Lockout** — بلوك تلقائي بعد 3 محاولات باسورد خاطئة.
* **Permissions System** — تحكم دقيق في صلاحيات المستخدمين.
* **Transfer Screen** — تحويل رصيد من حساب لحساب.
* **Transfer Log + Transfer Log Screen** — تتبع كامل لعمليات التحويل.

#### v3.0 — Currency Exchange

* **Currency Management** — إدارة العملات الموجودة في النظام.
* **Currencies List** — عرض جميع العملات.
* **Find Currency** — البحث عن عملة معينة.
* **Update Currency** — تحديث الـ Exchange Rate.
* **Currency Exchange Calculator** — تحويل قيمة من عملة إلى عملة أخرى.
* **Currency Exchange Main Screen** — شاشة مستقلة لإدارة وظائف الـ Currency Exchange.
* **Currencies.txt** — فصل تخزين بيانات العملات عن باقي بيانات النظام.

### 🚧 قيد التخطيط (المراحل القادمة)

* **اختبارات (Unit Testing)** — للتأكد من سلامة العمليات الحساسة (الرصيد، الصلاحيات، تسجيل الدخول، وعمليات Currency Exchange).
* **الانتقال لقاعدة بيانات حقيقية** — بدل التخزين في ملفات نصية (Flat Files).
* **فصل Declaration عن Implementation** — تقسيم الكلاسات لملفات `.h` / `.cpp` بالشكل القياسي في C++.
* **دعم CMake** — لتشغيل المشروع خارج بيئة Visual Studio.
* **تطوير Currency Exchange** — إضافة وظائف وتحسينات جديدة على نظام العملات.

> 📌 المشروع بيتطور على شكل Versions منفصلة، وكل نسخة بتضيف طبقة جديدة من الوظائف أو التحسينات على الـ Architecture بدل تحديث واحد ضخم دفعة واحدة.

---

## 🤝 المساهمة

المشروع شخصي حاليًا وقيد التطوير المستمر. أي اقتراحات أو Issues تفتحها على الريبو هتكون محل تقدير.

---

## 📄 الترخيص

لم يُحدَّد ترخيص رسمي للمشروع بعد. يُفضّل إضافة ملف `LICENSE` (مثل MIT) لتوضيح حقوق الاستخدام.

---

**المطور:** [Tarek Mahmoud Sayed](https://github.com/TarekMahmoudSayed)
