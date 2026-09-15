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
  - نظام تسجيل دخول (Login) أساسي.
- **العمليات المالية (Transactions)**
  - إيداع (Deposit) وسحب (Withdraw) من حساب العميل.
  - عرض إجمالي الأرصدة (Total Balances).
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
| `clsInputValidate.h` | التحقق من صحة المدخلات |
| `clsString.h` / `clsUtil.h` | أدوات مساعدة عامة (String handling & Utilities) |
| `Clients.txt` / `Users.txt` | تخزين البيانات (Flat File Storage) |

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

## 🔒 ملاحظة أمنية (النسخة الحالية)

النسخة الحالية بتخزن البيانات (بما فيها الـ PIN Code) كـ **Plain Text** في ملفات نصية، وده مناسب لغرض التعلّم والتطوير فقط، **مش موصى بيه في أي بيئة إنتاج حقيقية**. التحسينات الأمنية جزء أساسي من خارطة الطريق القادمة (تحت).

## 🗺️ خارطة الطريق (Roadmap) — قيد التطوير

المشروع في تطوير مستمر، والهدف من المراحل الجاية تحويله تدريجيًا من مشروع تعليمي لنظام أقرب للاحترافية الحقيقية:

- [ ] **تشفير كلمات المرور (Password Encryption)** — استخدام Hashing + Salt بدل التخزين الصريح.
- [ ] **نظام تسجيل الأحداث (Logging System)** — تسجيل كل العمليات المهمة (دخول، خروج، تعديلات) بالتاريخ والوقت.
- [ ] **قفل الحساب بعد محاولات دخول فاشلة (Login Lockout)** — بلوك تلقائي بعد 3 محاولات باسورد خاطئة.
- [ ] **نظام صلاحيات متكامل (Permissions System)** — تحكم دقيق فيما يقدر كل مستخدم يعمله.
- [ ] **تحويل الأموال بين الحسابات (Transfer Screen)** — شاشة تحويل رصيد من حساب لحساب.
- [ ] **لوج خاص بعمليات التحويل (Transfer Log + Transfer Log Screen)** — تتبّع كامل لكل عملية تحويل.
- [ ] **اختبارات (Testing)** — إضافة Unit Tests للتأكد من سلامة العمليات الحساسة (الرصيد، الصلاحيات، تسجيل الدخول).

> 📌 هذه التحسينات هتُنشر بشكل تدريجي على شكل Versions منفصلة (كل نسخة بتضيف طبقة جديدة من الأمان أو الوظائف)، بدل تحديث واحد ضخم دفعة واحدة.

## 🤝 المساهمة

المشروع شخصي حاليًا وقيد التطوير المستمر. أي اقتراحات أو Issues تفتحها على الريبو هتكون محل تقدير.

## 📄 الترخيص

لم يُحدَّد ترخيص رسمي للمشروع بعد. يُفضّل إضافة ملف `LICENSE` (مثل MIT) لتوضيح حقوق الاستخدام.

---

**المطور:** [Tarek Mahmoud Sayed](https://github.com/TarekMahmoudSayed)
