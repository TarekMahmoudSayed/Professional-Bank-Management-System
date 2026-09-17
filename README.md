# 🏦 Professional Bank Management System

نظام إدارة بنكي (Console Application) مبني بلغة **C++** باستخدام مبادئ البرمجة الكائنية (OOP)، بيوفر إدارة كاملة للعملاء والمستخدمين والعمليات المالية الأساسية.

---

## 📋 نظرة عامة

المشروع ده عبارة عن Bank Management System شغال من خلال الـ Console، بيحاكي عمليات البنوك الحقيقية زي إضافة العملاء، الإيداع، السحب، وإدارة صلاحيات المستخدمين، مع الاعتماد على مبادئ الـ Object-Oriented Programming بشكل كامل في تصميم الكود.

## ✨ المميزات الحالية

- **إدارة العملاء (Clients Management)**
  - إضافة، تعديل، حذف، والبحث عن عميل.
  - عرض قائمة كاملة بكل العملاء.
- **إدارة المستخدمين (Users Management)**
  - إضافة وتعديل وحذف المستخدمين.
  - نظام تسجيل دخول (Login) بحماية إضافية (تفاصيل تحت).
- **العمليات المالية (Transactions)**
  - إيداع (Deposit) وسحب (Withdraw) من حساب العميل.
  - **تحويل أموال بين الحسابات (Transfer)** مع تسجيل كامل لكل عملية تحويل (Transfer Log + شاشة عرض مخصصة).
  - عرض إجمالي الأرصدة (Total Balances).
- **الأمان (Security)**
  - **تشفير كلمات المرور (Password Encryption)** بدل التخزين الصريح.
  - **قفل الحساب بعد محاولات دخول فاشلة (Login Lockout)** — بلوك تلقائي بعد 3 محاولات باسورد خاطئة.
- **نظام تسجيل الأحداث (Logging System)**
  - تسجيل كل العمليات المهمة (دخول، خروج، تعديلات، تحويلات) بالتاريخ والوقت.
- **نظام الصلاحيات (Permissions System)**
  - تحكم دقيق فيما يقدر كل مستخدم يعمله حسب صلاحياته.
- **تصميم Object-Oriented**
  - Inheritance بين `clsPerson` و `clsBankClient` / `clsUser`.
  - فصل الشاشات (Screens) عن منطق البيانات (Business Logic).
  - استخدام `enum` بدل الـ Magic Numbers لحالات الحفظ والوضع.

## 🗂️ هيكل المشروع

| الملف | الوظيفة |
|---|---|
| `clsPerson.h/.cpp` | الكلاس الأساسي المشترك (الاسم، الإيميل، التليفون) |
| `clsBankClient.h` | كلاس العميل وكل عمليات الحساب البنكي |
| `clsUser.h` | كلاس المستخدم (الموظف/الأدمن) |
| `clsLoginScreen.h` | شاشة تسجيل الدخول |
| `clsMainScreen.h` | الشاشة الرئيسية والتنقل بين الأقسام |
| `clsClientListScreen.h` | عرض قائمة العملاء |
| `clsAddNewClientScreen.h` | إضافة عميل جديد |
| `clsUpdateClientScreen.h` | تعديل بيانات عميل |
| `clsDeleteClientScreen.h` | حذف عميل |
| `clsFindClientScreen.h` | البحث عن عميل |
| `clsDepositScreen.h` / `clsWithdrawScreen.h` | عمليات الإيداع والسحب |
| `clsTotalBalancesScreen.h/.cpp` | عرض إجمالي أرصدة كل العملاء |
| `clsManageUsersScreen.h` | إدارة المستخدمين |
| `clsTransferScreen.h` | تحويل الأموال بين الحسابات |
| `clsTransferLog.h` / `clsTransferLogScreen.h` | تسجيل وعرض عمليات التحويل |
| `clsLog.h` | تسجيل الأحداث العامة (Login, Logout, Actions...) |
| `clsEncryptionUtil.h` | تشفير كلمات المرور (Hashing) |
| `clsInputValidate.h` | التحقق من صحة المدخلات |
| `clsString.h` / `clsUtil.h` | أدوات مساعدة عامة (String handling & Utilities) |
| `Clients.txt` / `Users.txt` | تخزين البيانات (Flat File Storage) |
| `Logs.txt` / `TransferLog.txt` | ملفات تسجيل الأحداث والتحويلات |

## ⚙️ متطلبات التشغيل

- Windows + Visual Studio (2019 أو أحدث يُفضّل).
- المشروع بيستخدم ملفات `.vcxproj` الخاصة بـ Visual Studio.

### طريقة التشغيل

1. حمّل أو اعمل Clone للريبو:
   ```bash
   git clone https://github.com/TarekMahmoudSayed/Professional-Bank-Management-System.git
   ```
2. افتح ملف `Bank System Project.vcxproj` في Visual Studio.
3. اعمل Build ثم Run (`F5`).

## 🔒 ملاحظة أمنية (تحديث)

بعد التحديث الأخير، لم تعد كلمات المرور (PIN Codes) تُخزَّن كنص صريح؛ يتم الآن تشفيرها قبل الحفظ، بالإضافة إلى نظام قفل تلقائي للحساب بعد محاولات دخول فاشلة متكررة. رغم ذلك، يظل التخزين على شكل ملفات نصية (Flat Files) غير مناسب لبيئة إنتاج حقيقية على نطاق واسع، والانتقال لقاعدة بيانات حقيقية (SQL/NoSQL) يظل خطوة مستقبلية موصى بها.

## 🗺️ خارطة الطريق (Roadmap)

### ✅ تم إنجازه (v2.0)

- [x] **تشفير كلمات المرور (Password Encryption)** — استخدام Hashing بدل التخزين الصريح.
- [x] **نظام تسجيل الأحداث (Logging System)** — تسجيل كل العمليات المهمة (دخول، خروج، تعديلات) بالتاريخ والوقت.
- [x] **قفل الحساب بعد محاولات دخول فاشلة (Login Lockout)** — بلوك تلقائي بعد 3 محاولات باسورد خاطئة.
- [x] **نظام صلاحيات متكامل (Permissions System)** — تحكم دقيق فيما يقدر كل مستخدم يعمله.
- [x] **تحويل الأموال بين الحسابات (Transfer Screen)** — شاشة تحويل رصيد من حساب لحساب.
- [x] **لوج خاص بعمليات التحويل (Transfer Log + Transfer Log Screen)** — تتبّع كامل لكل عملية تحويل.

### 🚧 قيد التخطيط (المراحل القادمة)

- [ ] **اختبارات (Unit Testing)** — للتأكد من سلامة العمليات الحساسة (الرصيد، الصلاحيات، تسجيل الدخول).
- [ ] **الانتقال لقاعدة بيانات حقيقية** — بدل التخزين في ملفات نصية (Flat Files).
- [ ] **فصل Declaration عن Implementation** — تقسيم الكلاسات لملفات `.h` / `.cpp` بالشكل القياسي في C++.
- [ ] **دعم CMake** — لتشغيل المشروع خارج بيئة Visual Studio.

> 📌 المشروع بيتطور على شكل Versions منفصلة، كل نسخة بتضيف طبقة جديدة من الأمان أو الوظائف بدل تحديث واحد ضخم دفعة واحدة.

## 🤝 المساهمة

المشروع شخصي حاليًا وقيد التطوير المستمر. أي اقتراحات أو Issues تفتحها على الريبو هتكون محل تقدير.

## 📄 الترخيص

لم يُحدَّد ترخيص رسمي للمشروع بعد. يُفضّل إضافة ملف `LICENSE` (مثل MIT) لتوضيح حقوق الاستخدام.

---

**المطور:** [Tarek Mahmoud Sayed](https://github.com/TarekMahmoudSayed)
