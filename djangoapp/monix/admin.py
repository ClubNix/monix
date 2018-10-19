from import_export.admin import ImportExportModelAdmin
from django.contrib import admin

from .models import Member

class MemberAdmin(ImportExportModelAdmin): # used to allow import/export from admin panel.
    pass
    
admin.site.register(Member, MemberAdmin)

